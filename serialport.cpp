#include "serialport.h"

const std::map<SerialPort::FlowControl, QSerialPort::FlowControl> SerialPort::flowControlMap =
{{SerialPort::NoFlowControl,    QSerialPort::NoFlowControl},
 {SerialPort::SoftwareControl,  QSerialPort::SoftwareControl},
 {SerialPort::RTSControl,       QSerialPort::HardwareControl},
 {SerialPort::DTRControl,       QSerialPort::NoFlowControl}};


void SerialPort::setFlowControl(SerialPort::FlowControl flowControl)
{
    bool prevState = blockSignals(true);
    QSerialPort::setFlowControl(flowControlMap.at(flowControl));
    blockSignals(prevState);

    this->flowControl = flowControl;
}

qint64 SerialPort::readData(char *data, qint64 maxSize)
{
    if (flowControl == SerialPort::DTRControl)
    {
        // TODO implement
        return -1;

    }

    return QSerialPort::readData(data, maxSize);

}

qint64 SerialPort::readLineData(char *data, qint64 maxSize)
{
    if (flowControl == SerialPort::DTRControl)
    {
        // TODO implement
        return -1;
    }

    return QSerialPort::readLineData(data, maxSize);
}

qint64 SerialPort::writeData(const char *data, qint64 maxSize)
{
    if (flowControl == SerialPort::DTRControl)
    {
        // TODO implement
        return -1;
    }

    return QSerialPort::writeData(data, maxSize);
}


