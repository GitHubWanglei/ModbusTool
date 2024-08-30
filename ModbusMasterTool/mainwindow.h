#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libmodbus/modbus.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent* event);

private:
    Ui::MainWindow *ui;
    modbus_t *mb;
    bool isOpen;
    int timerId;
    QString portName;
    QStringList portNames;

    void configSerialPortParametersList();
    void scanSerialPortNames();
    void setConnectBtnStatus(bool isConnected);

    bool isInt(const QString &str);

public slots:
    void connectBtnClicked();
    void readRegister();
    void writeRegister();

};
#endif // MAINWINDOW_H
