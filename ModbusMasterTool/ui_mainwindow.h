/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *serialPortBox;
    QPushButton *connectBtn;
    QLabel *dataBitTitle;
    QLabel *parityTitle;
    QLabel *portTitle;
    QComboBox *port;
    QComboBox *dataBit;
    QLabel *baudRateTitle;
    QComboBox *baudRate;
    QComboBox *parity;
    QComboBox *stopBit;
    QLabel *stopBitTitle;
    QGroupBox *readGroupBox;
    QLabel *portTitle_2;
    QLineEdit *readDeviceID;
    QComboBox *readFunc;
    QLabel *portTitle_4;
    QLineEdit *readRegister;
    QLabel *portTitle_5;
    QLineEdit *readRegisterCount;
    QLabel *portTitle_3;
    QPushButton *readBtn;
    QLabel *readResultTitleLabel;
    QTextEdit *readResultTextView;
    QGroupBox *writeGroupBox;
    QLabel *portTitle_7;
    QLineEdit *writeDeviceID;
    QLabel *portTitle_8;
    QComboBox *writeFunc;
    QLabel *inputTipLabel;
    QTextEdit *writeValuesTextView;
    QPushButton *writeBtn;
    QLabel *writeResultLabel;
    QLabel *portTitle_12;
    QLineEdit *writeRegister;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(793, 364);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(true);
        serialPortBox = new QGroupBox(centralwidget);
        serialPortBox->setObjectName("serialPortBox");
        serialPortBox->setGeometry(QRect(20, 20, 191, 321));
        serialPortBox->setStyleSheet(QString::fromUtf8("#serialPortBox\n"
"{\n"
"border: 1px solid #dddddd;\n"
"margin-top:7px;\n"
"border-radius:8px;\n"
"background-color:  #dddddd;\n"
"}\n"
"#serialPortBox::title\n"
"{\n"
"subcontrol-origin:margin;\n"
"left:15px;\n"
"}"));
        connectBtn = new QPushButton(serialPortBox);
        connectBtn->setObjectName("connectBtn");
        connectBtn->setGeometry(QRect(40, 250, 101, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon_status_closed.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectBtn->setIcon(icon);
        dataBitTitle = new QLabel(serialPortBox);
        dataBitTitle->setObjectName("dataBitTitle");
        dataBitTitle->setEnabled(true);
        dataBitTitle->setGeometry(QRect(20, 150, 51, 21));
        parityTitle = new QLabel(serialPortBox);
        parityTitle->setObjectName("parityTitle");
        parityTitle->setEnabled(true);
        parityTitle->setGeometry(QRect(20, 110, 51, 21));
        portTitle = new QLabel(serialPortBox);
        portTitle->setObjectName("portTitle");
        portTitle->setGeometry(QRect(20, 33, 51, 16));
        port = new QComboBox(serialPortBox);
        port->setObjectName("port");
        port->setGeometry(QRect(70, 30, 101, 23));
        dataBit = new QComboBox(serialPortBox);
        dataBit->setObjectName("dataBit");
        dataBit->setGeometry(QRect(70, 150, 101, 21));
        baudRateTitle = new QLabel(serialPortBox);
        baudRateTitle->setObjectName("baudRateTitle");
        baudRateTitle->setEnabled(true);
        baudRateTitle->setGeometry(QRect(20, 70, 51, 21));
        baudRate = new QComboBox(serialPortBox);
        baudRate->setObjectName("baudRate");
        baudRate->setGeometry(QRect(70, 70, 101, 21));
        parity = new QComboBox(serialPortBox);
        parity->setObjectName("parity");
        parity->setGeometry(QRect(70, 110, 101, 21));
        stopBit = new QComboBox(serialPortBox);
        stopBit->setObjectName("stopBit");
        stopBit->setGeometry(QRect(70, 190, 101, 21));
        stopBitTitle = new QLabel(serialPortBox);
        stopBitTitle->setObjectName("stopBitTitle");
        stopBitTitle->setEnabled(true);
        stopBitTitle->setGeometry(QRect(20, 190, 51, 21));
        readGroupBox = new QGroupBox(centralwidget);
        readGroupBox->setObjectName("readGroupBox");
        readGroupBox->setGeometry(QRect(230, 20, 261, 321));
        readGroupBox->setStyleSheet(QString::fromUtf8("#readGroupBox\n"
"{\n"
"border: 1px solid #cccccc;\n"
"margin-top:7px;\n"
"border-radius:8px;\n"
"}\n"
"#readGroupBox::title\n"
"{\n"
"subcontrol-origin:margin;\n"
"left:15px;\n"
"}"));
        portTitle_2 = new QLabel(readGroupBox);
        portTitle_2->setObjectName("portTitle_2");
        portTitle_2->setGeometry(QRect(10, 43, 61, 16));
        readDeviceID = new QLineEdit(readGroupBox);
        readDeviceID->setObjectName("readDeviceID");
        readDeviceID->setGeometry(QRect(90, 40, 161, 23));
        readFunc = new QComboBox(readGroupBox);
        readFunc->setObjectName("readFunc");
        readFunc->setGeometry(QRect(90, 80, 161, 23));
        portTitle_4 = new QLabel(readGroupBox);
        portTitle_4->setObjectName("portTitle_4");
        portTitle_4->setGeometry(QRect(10, 123, 71, 16));
        readRegister = new QLineEdit(readGroupBox);
        readRegister->setObjectName("readRegister");
        readRegister->setGeometry(QRect(90, 120, 161, 23));
        portTitle_5 = new QLabel(readGroupBox);
        portTitle_5->setObjectName("portTitle_5");
        portTitle_5->setGeometry(QRect(10, 163, 71, 16));
        readRegisterCount = new QLineEdit(readGroupBox);
        readRegisterCount->setObjectName("readRegisterCount");
        readRegisterCount->setGeometry(QRect(90, 160, 161, 23));
        portTitle_3 = new QLabel(readGroupBox);
        portTitle_3->setObjectName("portTitle_3");
        portTitle_3->setGeometry(QRect(10, 83, 61, 16));
        readBtn = new QPushButton(readGroupBox);
        readBtn->setObjectName("readBtn");
        readBtn->setGeometry(QRect(170, 200, 80, 23));
        readResultTitleLabel = new QLabel(readGroupBox);
        readResultTitleLabel->setObjectName("readResultTitleLabel");
        readResultTitleLabel->setGeometry(QRect(10, 220, 71, 16));
        readResultTextView = new QTextEdit(readGroupBox);
        readResultTextView->setObjectName("readResultTextView");
        readResultTextView->setGeometry(QRect(10, 240, 241, 71));
        readResultTextView->setReadOnly(false);
        writeGroupBox = new QGroupBox(centralwidget);
        writeGroupBox->setObjectName("writeGroupBox");
        writeGroupBox->setGeometry(QRect(510, 20, 261, 321));
        writeGroupBox->setStyleSheet(QString::fromUtf8("#writeGroupBox\n"
"{\n"
"border: 1px solid #cccccc;\n"
"margin-top:7px;\n"
"border-radius:8px;\n"
"}\n"
"#writeGroupBox::title\n"
"{\n"
"subcontrol-origin:margin;\n"
"left:15px;\n"
"}"));
        portTitle_7 = new QLabel(writeGroupBox);
        portTitle_7->setObjectName("portTitle_7");
        portTitle_7->setGeometry(QRect(10, 43, 61, 16));
        writeDeviceID = new QLineEdit(writeGroupBox);
        writeDeviceID->setObjectName("writeDeviceID");
        writeDeviceID->setGeometry(QRect(90, 40, 161, 23));
        portTitle_8 = new QLabel(writeGroupBox);
        portTitle_8->setObjectName("portTitle_8");
        portTitle_8->setGeometry(QRect(10, 83, 61, 16));
        writeFunc = new QComboBox(writeGroupBox);
        writeFunc->setObjectName("writeFunc");
        writeFunc->setGeometry(QRect(90, 80, 161, 23));
        inputTipLabel = new QLabel(writeGroupBox);
        inputTipLabel->setObjectName("inputTipLabel");
        inputTipLabel->setGeometry(QRect(10, 160, 241, 16));
        writeValuesTextView = new QTextEdit(writeGroupBox);
        writeValuesTextView->setObjectName("writeValuesTextView");
        writeValuesTextView->setGeometry(QRect(10, 180, 241, 51));
        writeValuesTextView->setReadOnly(false);
        writeBtn = new QPushButton(writeGroupBox);
        writeBtn->setObjectName("writeBtn");
        writeBtn->setGeometry(QRect(170, 275, 80, 23));
        writeResultLabel = new QLabel(writeGroupBox);
        writeResultLabel->setObjectName("writeResultLabel");
        writeResultLabel->setGeometry(QRect(20, 277, 141, 20));
        writeResultLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        portTitle_12 = new QLabel(writeGroupBox);
        portTitle_12->setObjectName("portTitle_12");
        portTitle_12->setGeometry(QRect(10, 123, 71, 16));
        writeRegister = new QLineEdit(writeGroupBox);
        writeRegister->setObjectName("writeRegister");
        writeRegister->setGeometry(QRect(90, 120, 161, 23));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Modbus\344\270\262\345\217\243\350\257\273\345\206\231\345\267\245\345\205\267 v1.0", nullptr));
        serialPortBox->setTitle(QString());
        connectBtn->setText(QCoreApplication::translate("MainWindow", "  \346\211\223\345\274\200", nullptr));
        dataBitTitle->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        parityTitle->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        portTitle->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        baudRateTitle->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        stopBitTitle->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        readGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\357\274\232", nullptr));
        portTitle_2->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\234\272\345\234\260\345\235\200\357\274\232", nullptr));
        readDeviceID->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        portTitle_4->setText(QCoreApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        readRegister->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        portTitle_5->setText(QCoreApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217\357\274\232", nullptr));
        readRegisterCount->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        portTitle_3->setText(QCoreApplication::translate("MainWindow", "\345\212\237 \350\203\275 \347\240\201\357\274\232", nullptr));
        readBtn->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226", nullptr));
        readResultTitleLabel->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\347\273\223\346\236\234\357\274\232", nullptr));
        readResultTextView->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        writeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        portTitle_7->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\234\272\345\234\260\345\235\200\357\274\232", nullptr));
        writeDeviceID->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        portTitle_8->setText(QCoreApplication::translate("MainWindow", "\345\212\237 \350\203\275 \347\240\201\357\274\232", nullptr));
        inputTipLabel->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\345\200\274(\345\244\232\344\270\252\345\200\274\347\224\250\351\200\227\345\217\267\351\232\224\345\274\200\357\274\2141-on, 0-off)\357\274\232", nullptr));
        writeValuesTextView->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        writeBtn->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        writeResultLabel->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\346\210\220\345\212\237\357\274\201", nullptr));
        portTitle_12->setText(QCoreApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        writeRegister->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
