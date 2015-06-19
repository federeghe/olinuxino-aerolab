#ifndef GUI_SETTINGSTABSERIALPORT_H
#define GUI_SETTINGSTABSERIALPORT_H

#include "settingstab.hpp"

#include <QTabWidget>
#include <QRadioButton>

namespace Ui {
    class SettingsTabSerialPort;
}

/*! The enumeration representing the possible values
 *  for the stop bits. This is compliant with Qt
 *  enumeration.
 */
typedef enum {
    ONE=1,
    ONE_HALF=3,
    TWO=2
} ser_stop_bits_t;

/*! The enumeration representing the possible values
 *  for parity bits. This is compliant with Qt
 *  enumeration.
 */
typedef enum {
    NO_PARITY=0,
    EVEN=2,
    ODD=3,
    SPACE=4,
    MARK=5
} ser_parity_t;

/*! The enumeration representing the possible values
 *  for the flow control. This is compliant with Qt
 *  enumeration.
 */
typedef enum {
    NO_FC=0,
    XON_XOFF=2,
    HARDWARE=1
} ser_flow_control_t;

/*! Class for tab of serialport.
 */
class SettingsTabSerialPort : public SettingsTab {
        Q_OBJECT
public:

    /*! The constructor for tab of settings for serial port.
     *  \param QStringList the list of port available coming from
     *         a SerialPort object. 
     */
    explicit SettingsTabSerialPort(QStringList ports_available);
    ~SettingsTabSerialPort();    // Overridden

    /* abstract method implementation */
    void save_settings();
    void restore_settings();
    
    const char* get_name() const  { return "Serial Port"; }

    // Variuos getters:
    /*! It returns the serial port selected as index in the 
     *  list of port_available passed in the constructor
     */
    int get_ser_port()                          const { return this->ser_port; }
    /*! Getter for baud rate */
    int get_ser_baud_rate()                     const { return this->ser_baud_rate; }
    /*! Getter for data bits */
    unsigned char get_ser_data_bits()           const { return this->ser_data_bits; }
    /*! Getter for stop bits */
    ser_stop_bits_t get_ser_stop_bits()         const { return this->ser_stop_bits; }
    /*! Getter for parity bits */
    ser_parity_t get_ser_parity()               const { return this->ser_parity; }
    /*! Getter for flow control */
    ser_flow_control_t get_ser_flow_control()   const { return this->ser_flow_control; }
    /*! Getter for carrier detect */
    bool get_ser_carrier_detect()               const { return this->ser_carrier_detect; }
    /*! Getter for parity check */
    bool get_ser_parity_check()                 const { return this->ser_parity_check; }

private:

    Ui::SettingsTabSerialPort *ui;
    
    // Settings - SERIAL:
    QStringList ser_ports_available;
    int ser_port;
    int ser_baud_rate;
    unsigned char ser_data_bits;
    ser_stop_bits_t ser_stop_bits;
    ser_parity_t ser_parity;    // 'N', 'O', 'E', 'M', 'S'
    ser_flow_control_t ser_flow_control;    //  'N', 'X', 'H'
    bool ser_carrier_detect;
    bool ser_parity_check;

    QRadioButton **bitsRadio;
    QRadioButton **stopRadio;


};

#endif
