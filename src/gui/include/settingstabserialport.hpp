#ifndef GUI_SETTINGSTABSERIALPORT_H
#define GUI_SETTINGSTABSERIALPORT_H

#include "settingstab.hpp"

#include <QTabWidget>
#include <QRadioButton>

namespace Ui {
    class TabSerialPort;
}

typedef enum {
    ONE=1,
    ONE_HALF=3,
    TWO=2
} ser_stop_bits_t;

typedef enum {
    NO_PARITY=0,
    EVEN=2,
    ODD=3,
    SPACE=4,
    MARK=5
} ser_parity_t;

typedef enum {
    NO_FC=0,
    XON_XOFF=2,
    HARDWARE=1
} ser_flow_control_t;

/*! Class for tab of serialport.
 */
class SettingsTabSerialPort : public SettingsTab {

public:

    // Construtor/Destructor
    explicit SettingsTabSerialPort(QStringList ports_available);
    ~SettingsTabSerialPort();    // Overridden

    // Abstract methods implementation:
    void save_settings();
    void restore_settings();

    // Variuos getters:    
    int get_ser_port()                            const { return this->ser_port; }
    int get_ser_baud_rate()                     const { return this->ser_baud_rate; }
    unsigned char get_ser_data_bits()            const { return this->ser_data_bits; }
    ser_stop_bits_t get_ser_stop_bits()            const { return this->ser_stop_bits; }
    ser_parity_t get_ser_parity()                 const { return this->ser_parity; }
    ser_flow_control_t get_ser_flow_control()     const { return this->ser_flow_control; }
    bool get_ser_carrier_detect()                 const { return this->ser_carrier_detect; }
    bool get_ser_parity_check()                 const { return this->ser_parity_check; }

private:

    Ui::TabSerialPort *ui;
    
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
