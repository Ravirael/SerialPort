#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>

class SerialPort : public QSerialPort
{
public:
    SerialPort();
};

#endif // SERIALPORT_H