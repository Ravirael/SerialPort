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

protected:
    virtual qint64 readData(char *data, qint64 maxSize) override;
    virtual qint64 readLineData(char *data, qint64 maxSize) override;
    virtual qint64 writeData(const char *data, qint64 maxSize) override;


private:
    const static std::map<SerialPort::FlowControl, QSerialPort::FlowControl> flowControlMap;

    FlowControl flowControl = FlowControl::NoFlowControl;

};

#endif // SERIALPORT_H
