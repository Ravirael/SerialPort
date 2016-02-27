#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_actionRefresh_ports_triggered();
    setupComboBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupComboBoxes()
{
    ui->baudRateCB->setMapping({{"115200",  QSerialPort::Baud115200},
                                {"57600",   QSerialPort::Baud57600},
                                {"38400",   QSerialPort::Baud38400},
                                {"19200",   QSerialPort::Baud19200},
                                {"9600",    QSerialPort::Baud9600},
                                {"4800",    QSerialPort::Baud4800},
                                {"2400",    QSerialPort::Baud2400},
                                {"1200",    QSerialPort::Baud1200}});

    ui->dataBitsCB->setMapping({{"7", SerialPort::Data7},
                                {"8", SerialPort::Data8}});

    ui->stopBitsCB->setMapping({{"1",   SerialPort::OneStop},
                                {"2",   SerialPort::TwoStop},
                                {"1,5", SerialPort::OneAndHalfStop}});

    ui->flowControlCB->setMapping({{"None",     SerialPort::NoFlowControl},
                                   {"XON/XOFF", SerialPort::SoftwareControl},
                                   {"RTS/CTS",  SerialPort::RTSControl},
                                   {"DTR/DSR",  SerialPort::DTRControl}});

    ui->parityCB->setMapping({{"No parity", SerialPort::NoParity},
                              {"Even",      SerialPort::EvenParity},
                              {"Odd",       SerialPort::OddParity}});
}

void MainWindow::on_actionRefresh_ports_triggered()
{
    auto portsList = QSerialPortInfo::availablePorts();
    std::vector<std::pair<QString, QSerialPortInfo>> portsMapping;

    for (auto &portInfo : portsList)
    {
        portsMapping.push_back({portInfo.portName(), portInfo});
    }

    ui->serialPortInfoCB->setMapping(portsMapping);
}