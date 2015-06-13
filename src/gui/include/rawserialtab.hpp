#include <QTabWidget>
#include "logic/include/serialport.hpp"
#include "settingstabserialport.hpp"

namespace Ui {
    class RawSerialTab;
}

/*! This class represent a tab for raw serial textbox in the main window
 *
 */
class RawSerialTab : public QWidget {
    Q_OBJECT
public:
    
    RawSerialTab();
    ~RawSerialTab();
    
    /*! This method returns the list of all available serial ports.
     *  note: this list doesn't update automatically, you need to create
     *        a new object to refresh this list.
     */
    QStringList get_list_ports_available() const { return this->list_ports_available; }

	/*! Connect signal. When you call this, the serial port is (hopefully) opened and
	 * the received text start to be written in console.
	 * \return true in case of success, false otherwise.
	 */
	bool serial_connect();
	
	/*! Disconnect signal: close the serial port.
	 * \return always true
	 */
	bool serial_disconnect();

	/*! Add a slot to serial receive data
	 *
	 */
	void add_slot(const char*);

	/*! Returns the settings tab to add to settings window
	 *
	 */
	SettingsTab* get_settings_tab() const {return this->settings_tab; }

private:

	Ui::RawSerialTab *ui;

	SettingsTabSerialPort *settings_tab;
	SerialPort *serial_port;
	QStringList list_ports_available;

};