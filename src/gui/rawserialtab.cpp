#include "rawserialtab.hpp"
#include "ui_rawserialtab.h"

#include <QScrollBar>

RawSerialTab::RawSerialTab() : QWidget(0), ui(new Ui::RawSerialTab) {

	ui->setupUi(this);

	// Create a generic serialport object.
	this->serial_port = new SerialPort();

	// Read the list of all available ports.
	list_ports_available = serial_port->get_list();
	
	// Create the settingstab
	this->settings_tab = new SettingsTabSerialPort(list_ports_available);
	
	this->add_slot(SLOT(printToDataEdit()));
}

RawSerialTab::~RawSerialTab() {
	delete this->serial_port;
}

void RawSerialTab::add_slot(const char* slot) {
	// Connect a slot to readiness of serial receiver. Usually
	// only one slot has sense: only one can read from serial port.
	connect(this->serial_port, SIGNAL(readyRead()), this, slot);
}

bool RawSerialTab::serial_connect() {

    int selected = this->settings_tab->get_ser_port();
    if (selected >= 0) {
        ui->rawDataEdit->append(this->serial_port->get_list()[selected] + ": connecting...\n");
        
        if ( this->serial_port->open_port( selected,
                                this->settings_tab->get_ser_baud_rate(),
                                this->settings_tab->get_ser_data_bits(),
                                this->settings_tab->get_ser_stop_bits(),
                                this->settings_tab->get_ser_parity(),
                                this->settings_tab->get_ser_flow_control(),
                                this->settings_tab->get_ser_carrier_detect(),
                                this->settings_tab->get_ser_parity_check()                                
                                )	// End of open port
                                
            )	// End of if 
            {
                ui->rawDataEdit->append("++ CONNECTED!\n\n");
				return true;
            } else {
                ui->rawDataEdit->append("-- UNABLE TO CONNECT.\n\n");
                return false;
            }
    }
    return false;
}

bool RawSerialTab::serial_disconnect() {
        this->serial_port->close();
        ui->rawDataEdit->append("\n\nDISCONNECTED!\n");
        return true;
}

void RawSerialTab::printToDataEdit() {
    QByteArray data = this->serial_port->readRawData();
    // Add text
    ui->rawDataEdit->append(QString(data));
    // Then scroll to down
    QScrollBar *bar = ui->rawDataEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}
