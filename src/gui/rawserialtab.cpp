#include "rawserialtab.hpp"
#include "ui_rawserialtab.h"

RawSerialTab::RawSerialTab() : QWidget(0), ui(new Ui::RawSerialTab) {

	ui->setupUi(this);

	// Create a generic serialport object.
	this->serialPort = new SerialPort();

	// Read the list of all available ports.
	list_ports_available = serialPort->get_list();
	
	// Create the settingstab
	this->settingsTab = new SettingsTabSerialPort(list_ports_available);
}

RawSerialTab::~RawSerialTab() {
	delete this->serialPort;
}

void RawSerialTab::add_slot(const char* slot) {
	connect(this->serialPort, SIGNAL(readyRead()), this, slot);
}