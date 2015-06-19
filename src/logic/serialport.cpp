#include "serialport.hpp"

#include <QtSerialPort/QtSerialPort>

#define UNUSED(x) (void)(x)        // Macro to avoid warning

SerialPort::SerialPort() : QSerialPort() {
    // Save the current serial port info.
    this->infos = QSerialPortInfo::availablePorts();    
}

SerialPort::~SerialPort() {        

}

QStringList SerialPort::get_list() const {
    
    QStringList to_return;
    
    foreach(QSerialPortInfo info, this->infos) {
        // We return the info in this format: "name (desription)"
        to_return << info.portName() + " (" + (!info.description().isEmpty() ? info.description() : "no info") + ")";
    }
    
    return to_return;
}

bool SerialPort::open_port(int selected, int baud_rate, int data_bits, int stop_bits,
              int parity, int flow_control, bool carrier_detect, 
              bool parity_check) { // Note: carrier_detect and parity_check is ignored
                  
    // Let's set the settings for the serial port
    this->setPortName(this->infos[selected].portName());
    this->setBaudRate((QSerialPort::BaudRate)baud_rate);
    this->setDataBits((QSerialPort::DataBits)data_bits);
    this->setStopBits((QSerialPort::StopBits)stop_bits);
    this->setParity((QSerialPort::Parity)parity);
    this->setFlowControl((QSerialPort::FlowControl)flow_control);                  
  
    UNUSED(carrier_detect);    // Not implemented in Qt
    UNUSED(parity_check);      // Not implemented in Qt
  
    // Finally, let's open the Serial!
    if (this->open(QIODevice::ReadWrite)) {
      return true;
    }
  
    return false;
}