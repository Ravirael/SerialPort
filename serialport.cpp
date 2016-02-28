#include "serialport.h"

#ifdef Q_OS_WIN32
    #include <windows.h>
#endif

const std::map<SerialPort::FlowControl, QSerialPort::FlowControl> SerialPort::flowControlMap =
{{SerialPort::NoFlowControl,    QSerialPort::NoFlowControl},
 {SerialPort::SoftwareControl,  QSerialPort::SoftwareControl},
 {SerialPort::RTSControl,       QSerialPort::HardwareControl},
 {SerialPort::DTRControl,       QSerialPort::NoFlowControl}};

#ifdef Q_OS_WIN32
bool SerialPort::getDcb(DCB *dcb)
{
    ZeroMemory(dcb, sizeof(DCB));
    dcb->DCBlength = sizeof(DCB);

    if (!GetCommState(handle(), dcb)) {
        error(QSerialPort::UnknownError);
        return false;
    }
    return true;
}
#endif


void SerialPort::setFlowControl(SerialPort::FlowControl flowControl)
{
    this->flowControl = flowControl;

#ifdef Q_OS_WIN32
    DCB dcb;
    if (!getDcb(&dcb))
        return false;

    dcb.fInX = FALSE;
    dcb.fOutX = FALSE;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    dcb.fDtrControl = DTR_CONTROL_DISABLE;

    switch (flowControl) {
    case SerialPort::NoFlowControl:
        break;
    case SerialPort::SoftwareControl:
        dcb.fInX = TRUE;
        dcb.fOutX = TRUE;
        break;
    case SerialPort::RTSControl:
        dcb.fOutxCtsFlow = TRUE;
        dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
        break;
    case SerialPort::DTRControl:
        dcb.fOutxDsrFlow = TRUE;
        dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
        break;
    default:
        break;
    }

    setDcb(&dcb);
#endif

}




