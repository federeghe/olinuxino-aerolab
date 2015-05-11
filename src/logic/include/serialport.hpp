#ifndef LOGIC_SERIALPORT_H
#define LOGIC_SERIALPORT_H

#include <QtSerialPort/QtSerialPort>

class SerialPort : QtSerialPort
{
public:
	SerialPort();
	QString *get_list() const;
	void select_device(const QString);
	void init();
private:

}

#endif