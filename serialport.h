#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QObject>

#include <map>

class SerialPort : public QSerialPort
{
    Q_OBJECT



public:
    enum FlowControl
    {
        NoFlowControl = 0, RTSControl, SoftwareControl, DTRControl
    };

    using QSerialPort::QSerialPort;

    void setFlowControl(FlowControl flowControl);

#ifdef Q_OS_WIN32
    bool getDcb(DCB *dcb);
#endif


private:
    const static std::map<SerialPort::FlowControl, QSerialPort::FlowControl> flowControlMap;

    FlowControl flowControl = FlowControl::NoFlowControl;

};

#endif // SERIALPORT_H
