#ifndef LOGIC_SERIALPORT_H
#define LOGIC_SERIALPORT_H

#include <QtSerialPort/QtSerialPort>

/*! SerialPort is a wapper of QSerialPort.
 */
class SerialPort : public QSerialPort
{
	Q_OBJECT
public:
	/*! It creates a new SerialPort object. You have to create a new object
	 *  every time resources (i.e. available serial port in the system) change.
	 *  Trying to open a serial port that doesn't exist anymore, produce an
	 *  unpredictable behaviour.
	 */
    SerialPort();
    ~SerialPort();
    
    /*! Get the list associated with this serial port object. The list is updated
     *  only at costruction of this object, so in order to refresh it, you have to
     *  create a new SerialPort object.
     */
    QStringList get_list() const;

	/*! A wapper for open() method: it accepts all serial parameters and
	 * open the object. You can also call directly single options and
	 * open it.
	 *
	 * \note carrier_detect and parity_check is ignored due to missing
	 *       implementation in Qt 
	 */
    bool open_port(int selected, int baud_rate, int data_bits, int stop_bits,
              int parity, int flow_control, bool carrier_detect, 
              bool parity_check);
    
    /*! A wrapper for readAll()
    */
    QByteArray readRawData() { return this->readAll(); }

private:
    QList<QSerialPortInfo> infos;

};

#endif
