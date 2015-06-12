#ifndef LOGIC_SERIALPORT_H
#define LOGIC_SERIALPORT_H

#include <QtSerialPort/QtSerialPort>
//#include <QSerialPortInfo>

class SerialPort : public QSerialPort
{
public:
####SerialPort();
####~SerialPort();
####QStringList get_list() const;
####bool open_port(int selected, int baud_rate, int data_bits, int stop_bits,
############  int parity, int flow_control, bool carrier_detect, 
############  bool parity_check);################################
####
####QByteArray readRawData() { return this->readAll(); }

private:
####QList<QSerialPortInfo> infos;

};

#endif