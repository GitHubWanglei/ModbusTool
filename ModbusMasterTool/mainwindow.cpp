#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QStringList>
#include <QComboBox>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(width(), height());
    this->setWindowIcon(QIcon(":/images/logo.png"));

    this->isOpen = false;

    this->configSerialPortParametersList();

    QObject::connect(ui->connectBtn, SIGNAL(clicked()), this, SLOT(connectBtnClicked()));

    scanSerialPortNames();

    setConnectBtnStatus(this->isOpen);

    QObject::connect(ui->readBtn, SIGNAL(clicked()), this, SLOT(readRegister()));
    QObject::connect(ui->writeBtn, SIGNAL(clicked()), this, SLOT(writeRegister()));
    QObject::connect(this->ui->port, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index){
        qDebug() << index;
        if (index > 0 && index < this->portNames.size()) {
            this->portName = this->portNames.at(index);
        }
    });
    QObject::connect(ui->readFunc, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index){
        QString tip;
        if (index == 0) {
            tip = "读取结果(位)：";
        } else if (index == 1) {
            tip = "读取结果(位)：";
        } else if (index == 2) {
            tip = "读取结果(字)：";
        } else {
            tip = "读取结果(字)：";
        }
        this->ui->readResultTitleLabel->setText(tip);
    });
    QObject::connect(ui->writeFunc, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index){
        QString tip;
        if (index == 0) {
            tip = "写入值(单个,位操作,1-on,0-off):";
        } else if (index == 1) {
            tip = "写入值(单个,字操作):";
        } else if (index == 2) {
            tip = "写入值(多个,位操作,用逗号隔开,1-on,0-off):";
        } else {
            tip = "写入值(多个,字操作,逗号隔开):";
        }
        this->ui->inputTipLabel->setText(tip);
    });

    QIntValidator *validator1 = new QIntValidator(1, 247, this);
    this->ui->readDeviceID->setValidator(validator1);
    QIntValidator *validator2 = new QIntValidator(0, 0xffff, this);
    this->ui->readRegister->setValidator(validator2);
    QIntValidator *validator3 = new QIntValidator(1, 0xff, this);
    this->ui->readRegisterCount->setValidator(validator3);

    this->ui->writeDeviceID->setValidator(validator1);
    this->ui->writeRegister->setValidator(validator2);

    this->ui->writeResultLabel->clear();

    timerId = startTimer(1000);
}

void MainWindow::timerEvent(QTimerEvent* event) {
    if (event->timerId() == timerId && !isOpen) {
        QStringList newPortnames;
        foreach (const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
            newPortnames << info.portName();
        }
        if (this->portNames == newPortnames) {
            return;
        }

        this->portNames = newPortnames;

        if (this->portNames.size() > 0) {

            this->ui->port->clear();
            this->ui->port->addItems(this->portNames);

            if (this->portName.isEmpty()) {
                this->portName = this->ui->port->currentText();
            } else {
                if (this->portNames.contains(this->portName)) {
                    this->ui->port->setCurrentText(this->portName);
                } else {
                    this->portName = this->ui->port->currentText();
                }
            }

        } else {
            this->ui->port->clear();
            this->portName = "";
        }

    }
}

void MainWindow::setConnectBtnStatus(bool isConnected) {
    if (isConnected) {
        QPixmap pixmap(":/images/icon_status_open.png");
        this->ui->connectBtn->setIcon(QIcon(pixmap));
        this->ui->connectBtn->setText("  关闭");
        this->ui->port->setEnabled(false);
        this->ui->baudRate->setEnabled(false);
        this->ui->parity->setEnabled(false);
        this->ui->dataBit->setEnabled(false);
        this->ui->stopBit->setEnabled(false);
    } else {
        QPixmap pixmap(":/images/icon_status_closed.png");
        this->ui->connectBtn->setIcon(QIcon(pixmap));
        this->ui->connectBtn->setText("  打开");
        this->ui->port->setEnabled(true);
        this->ui->baudRate->setEnabled(true);
        this->ui->parity->setEnabled(true);
        this->ui->dataBit->setEnabled(true);
        this->ui->stopBit->setEnabled(true);
    }
}

void MainWindow::scanSerialPortNames() {
    foreach (const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
        if (!(this->portNames.contains(info.portName()))) {
            this->portNames << info.portName();
        }
    }
    if (this->portNames.size() > 0) {
        this->ui->port->addItems(this->portNames);
        this->portName = this->ui->port->currentText();
    } else {
        this->ui->port->clear();
        this->portName = "";
    }
}

void MainWindow::configSerialPortParametersList() {
    QStringList baudList = {"9600", "14400", "19200", "38400", "56000", "57600", "115200", "128000"};
    this->ui->baudRate->addItems(baudList);
    QStringList parityList = {"NONE", "ODD", "EVEN"};
    this->ui->parity->addItems(parityList);
    QStringList dataBitList = {"8", "5", "6", "7"};
    this->ui->dataBit->addItems(dataBitList);
    QStringList stopBitList = {"1", "2"};
    this->ui->stopBit->addItems(stopBitList);

    QStringList readFuncNumber = {"0x01", "0x02", "0x03", "0x04"};
    this->ui->readFunc->addItems(readFuncNumber);
    this->ui->readFunc->setCurrentIndex(2);
    this->ui->readResultTitleLabel->setText("读取结果(字)：");

    QStringList writeFuncNumber = {"0x05", "0x06", "0x0F", "0x10"};
    this->ui->writeFunc->addItems(writeFuncNumber);
    this->ui->writeFunc->setCurrentIndex(1);
    this->ui->inputTipLabel->setText("写入值(单个,字操作):");
}

void MainWindow::connectBtnClicked() {
    if (!isOpen) {
        QString portName = this->ui->port->currentText();
        if (portName.isEmpty()) {
            QMessageBox::information(NULL, "提示", "未检测到串口.");
            return;
        }

        this->killTimer(this->timerId);

        QString baudRateStr = this->ui->baudRate->currentText();
        int baudRate_int = baudRateStr.toInt();
        qDebug("波特率：%d", baudRate_int);

        char parity_char = 'N';
        QString parityStr = this->ui->parity->currentText();
        if (parityStr == "NONE") parity_char = 'N';
        if (parityStr == "ODD") parity_char = 'O';
        if (parityStr == "EVEN") parity_char = 'E';
        qDebug("校验位：%c", parity_char);

        QString dataBitStr = this->ui->dataBit->currentText();
        int dataBit_int = dataBitStr.toInt();
        qDebug("数据位：%d", dataBit_int);

        QString stopBitStr = this->ui->stopBit->currentText();
        int stopBit_int = stopBitStr.toInt();
        qDebug("停止位：%d", stopBit_int);

        QString prefix = "\\\\.\\";
        QString newPortName = prefix.append(portName.toStdString().c_str());
        qDebug("new 串口号：%s", qPrintable(newPortName));
        mb = modbus_new_rtu(newPortName.toStdString().c_str(), baudRate_int, parity_char, dataBit_int, stopBit_int);
        int res = modbus_connect(mb);
        if (res == -1) {
            QMessageBox::critical(this, "提示", "打开失败！");
            return;
        }
        this->portName = portName;
    } else {
        modbus_close(mb);
        modbus_free(mb);

        this->timerId = startTimer(1000);
    }
    isOpen = !isOpen;
    setConnectBtnStatus(isOpen);
}

void MainWindow::readRegister() {

    if (!isOpen) {
        QMessageBox::warning(this, "提示", "请先打开串口！");
        return;
    }

    QString deviceIdStr = this->ui->readDeviceID->text();
    if (deviceIdStr.trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入从机地址！");
        return;
    }
    int deviceID = deviceIdStr.toInt();
    if (deviceID == 0 || deviceID > 247) {
        QMessageBox::warning(this, "提示", "从机地址范围为1~247，请重新输入！");
        return;
    }
    qDebug("从机地址：%d", deviceID);

    QString funcNumStr = this->ui->readFunc->currentText();
    int funcNum = 0x03;
    if (funcNumStr == "0x01") funcNum = 0x01;
    if (funcNumStr == "0x02") funcNum = 0x02;
    if (funcNumStr == "0x03") funcNum = 0x03;
    if (funcNumStr == "0x04") funcNum = 0x04;
    qDebug("功能码：%d", funcNum);

    QString registerStr = this->ui->readRegister->text();
    if (registerStr.trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入寄存器地址！");
        return;
    }
    int register_int = registerStr.toInt();
    if (register_int > 0xffff) {
        QMessageBox::warning(this, "提示", "寄存器地址不能大于0xffff");
        return;
    }
    qDebug("寄存器地址：%d", register_int);

    QString registerCountStr = this->ui->readRegisterCount->text();
    if (registerCountStr.trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入寄存器数量！");
        return;
    }
    int registerCount = registerCountStr.toInt();
    if (registerCount == 0 || registerCount > 0xff) {
        QMessageBox::warning(this, "提示", "寄存数量为1~0xff，请重新输入！");
        return;
    }
    qDebug("寄存器数量：%d", registerCount);

    modbus_set_slave(this->mb, deviceID);
    QString result = "";
    if (funcNum == 0x01) {
        uint8_t bits[0xff] = {0};
        int res = modbus_read_bits(this->mb, register_int, registerCount, bits);
        if (res == -1) {
            QMessageBox::warning(this, "提示", "读取失败！");
            return;
        }
        for (int i = 0; i < registerCount; i++) {
            result += QString::number(bits[i]);
        }
    } else if (funcNum == 0x02) {
        uint8_t bits[0xff] = {0};
        int res = modbus_read_input_bits(this->mb, register_int, registerCount, bits);
        if (res == -1) {
            QMessageBox::warning(this, "提示", "读取失败！");
            return;
        }
        for (int i = 0; i < registerCount; i++) {
            result += QString::number(bits[i]);
        }
    } else if (funcNum == 0x03) {
        uint16_t values[0xff] = {0};
        int res = modbus_read_registers(this->mb, register_int, registerCount, values);
        if (res == -1) {
            QMessageBox::warning(this, "提示", "读取失败！");
            return;
        }
        for (int i = 0; i < registerCount; i++) {
            if (i > 0) {
                result += ", ";
            }
            if (i == 0) {
                result += "十进制(uint16)：\n";
            }
            result += QString::number(values[i]);
        }
        result += "\n";
        for (int i = 0; i < registerCount; i++) {
            if (i > 0) {
                result += ", ";
            }
            if (i == 0) {
                result += "十进制(int16)：\n";
            }
            result += QString::number((int16_t)values[i]);
        }
        result += "\n";
        for (int i = 0; i < registerCount; i++) {
            if (i > 0) {
                result += ", ";
            }
            if (i == 0) {
                result += "十六进制：\n";
            }
            result += "0x";
            result += QString::asprintf("%04X", values[i]);
        }
    } else if (funcNum == 0x04) {
        uint16_t values[0xff] = {0};
        int res = modbus_read_input_registers(this->mb, register_int, registerCount, values);
        if (res == -1) {
            QMessageBox::warning(NULL, "提示", "读取失败！");
            return;
        }
        for (int i = 0; i < registerCount; i++) {
            if (i > 0) {
                result += ", ";
            }
            if (i == 0) {
                result += "十进制(uint16)：\n";
            }
            result += QString::number(values[i]);
        }
        result += "\n";
        for (int i = 0; i < registerCount; i++) {
            if (i > 0) {
                result += ", ";
            }
            if (i == 0) {
                result += "十进制(int16)：\n";
            }
            result += QString::number((int16_t)values[i]);
        }
        result += "\n";
        for (int i = 0; i < registerCount; i++) {
            if (i > 0) {
                result += ", ";
            }
            if (i == 0) {
                result += "十六进制：\n";
            }
            result += "0x";
            result += QString::asprintf("%04X", values[i]);
        }
    } else {
        // never arrive here.
        return;
    }

    this->ui->readResultTextView->clear();
    this->ui->readResultTextView->setText(result);

}

void MainWindow::writeRegister() {

    if (!isOpen) {
        QMessageBox::warning(this, "提示", "请先打开串口！");
        return;
    }

    QString deviceIdStr = this->ui->writeDeviceID->text();
    if (deviceIdStr.trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入从机地址！");
        return;
    }
    int deviceID = deviceIdStr.toInt();
    if (deviceID == 0 || deviceID > 247) {
        QMessageBox::warning(this, "提示", "从机地址范围为1~247，请重新输入！");
        return;
    }
    qDebug("从机地址：%d", deviceID);

    QString funcNumStr = this->ui->writeFunc->currentText();
    int funcNum = 0x06;
    if (funcNumStr == "0x05") funcNum = 0x05;
    if (funcNumStr == "0x06") funcNum = 0x06;
    if (funcNumStr == "0x0F") funcNum = 0x0F;
    if (funcNumStr == "0x10") funcNum = 0x10;
    qDebug("功能码：%d", funcNum);

    QString registerStr = this->ui->writeRegister->text();
    if (registerStr.trimmed().isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入寄存器地址！");
        return;
    }
    int register_int = registerStr.toInt();
    if (register_int > 0xffff) {
        QMessageBox::warning(this, "提示", "寄存器地址不能大于0xffff");
        return;
    }
    qDebug("寄存器地址：%d", register_int);

    QString valuesStr = this->ui->writeValuesTextView->toPlainText();
    qDebug("intpu values: %s", valuesStr.toStdString().c_str());


    if (funcNum == 0x05) {
        QString trimedStr = valuesStr.trimmed();
        if (trimedStr != "0" && trimedStr != "1") {
            QMessageBox::warning(this, "提示", "单个写入值只能为0或1，其中0为off，1为on.");
            return;
        }
        this->ui->writeResultLabel->clear();
        modbus_set_slave(this->mb, deviceID);
        int status = trimedStr.toInt();
        int res = modbus_write_bit(this->mb, register_int, status);
        if (res == -1) {
            this->ui->writeResultLabel->setStyleSheet("color:red;");
            this->ui->writeResultLabel->setText("写入失败！");
            QMessageBox::warning(this, "提示", "写入失败！");
            return;
        }
        this->ui->writeResultLabel->setStyleSheet("color:green;");
        this->ui->writeResultLabel->setText("写入成功！");

    } else if (funcNum == 0x06) {
        QString trimedStr = valuesStr.trimmed();
        qDebug() << "trimedStr: " + trimedStr;
        if (!isInt(trimedStr)) {
            QMessageBox::warning(this, "提示", "单个写入值" + trimedStr + "不是整数！");
            return;
        }
        this->ui->writeResultLabel->clear();
        modbus_set_slave(this->mb, deviceID);
        uint16_t value = (uint16_t)trimedStr.toInt();
        int res = modbus_write_register(this->mb, register_int, value);
        if (res == -1) {
            this->ui->writeResultLabel->setStyleSheet("color:red;");
            this->ui->writeResultLabel->setText("写入失败！");
            QMessageBox::warning(this, "提示", "写入失败！");
            return;
        }
        this->ui->writeResultLabel->setStyleSheet("color:green;");
        this->ui->writeResultLabel->setText("写入成功！");

    } else {
        valuesStr.replace(",", " ");
        valuesStr.replace("，", " ");
        qDebug("values: %s", valuesStr.toStdString().c_str());

        std::vector<uint8_t> uint8List;
        std::vector<uint16_t> uint16List;
        QStringList stringList = valuesStr.split(" ", Qt::SkipEmptyParts);
        for (const QString &valueStr : stringList) {
            qDebug() << valueStr;
            if (funcNum == 0x0F) {
                if (valueStr != "0" && valueStr != "1") {
                    QMessageBox::warning(this, "提示", "写入值只能为0或1，其中0为off，1为on.");
                    return;
                }
                uint8List.push_back(valueStr.toInt());
            } else { // 0x10
                if (!isInt(valueStr)) {
                    QMessageBox::warning(this, "提示", "写入值" + valueStr + "不是整数！");
                    return;
                }
                uint16List.push_back(valueStr.toInt());
            }
        }

        this->ui->writeResultLabel->clear();
        modbus_set_slave(this->mb, deviceID);
        int res = 0;
        if (funcNum == 0x0F) {
            res = modbus_write_bits(this->mb, register_int, uint8List.size(), uint8List.data());
        } else { // 0x10
            res = modbus_write_registers(this->mb, register_int, uint16List.size(), uint16List.data());
        }
        if (res == -1) {
            this->ui->writeResultLabel->setStyleSheet("color:red;");
            this->ui->writeResultLabel->setText("写入失败！");
            QMessageBox::warning(this, "提示", "写入失败！");
            return;
        }
        this->ui->writeResultLabel->setStyleSheet("color:green;");
        this->ui->writeResultLabel->setText("写入成功！");
    }

}

bool MainWindow::isInt(const QString &str) {
    if (str.isEmpty()) return false;
    bool ok = false;
    str.toInt(&ok);
    return ok;
}

MainWindow::~MainWindow()
{
    delete ui;
}
