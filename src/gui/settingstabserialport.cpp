#include "settingstabserialport.hpp"
#include "ui_settingstabserialport.h"

#include <QShowEvent>
#include <QtCore/QtGlobal>


SettingsTabSerialPort::SettingsTabSerialPort(QStringList ports_available) 
                                        : ser_ports_available(ports_available) {
                                             
	ui->setupUi(this);

	// Init radio choices pointers:
    this->bitsRadio  = new QRadioButton*[5]
    		{ui->bits5Radio, ui->bits6Radio, ui->bits7Radio, ui->bits8Radio, ui->bits9Radio };
    this->stopRadio  = new QRadioButton*[3]
            {ui->stopbits1Radio, ui->stopbits15Radio, ui->stopbits2Radio };
}

SettingsTabSerialPort::~SettingsTabSerialPort() {
	delete[] this->bitsRadio;
	delete[] this->stopRadio;
}

void SettingsTabSerialPort::save_settings() {
	// Save combobox values:
	this->ser_baud_rate 	= ui->baudrateCmb->currentText().toInt();
	this->ser_parity		= (ser_parity_t) ui->parityCmb->currentIndex();
	this->ser_flow_control	= (ser_flow_control_t) ui->flowCmb->currentIndex();

	// Save radio buttons:
	for (int i=0; i<5; i++) { 
		if (this->bitsRadio[i]->isChecked()) {  
			this->ser_data_bits = i+5;
			break;
		} 
	}

	for (int i=0; i<3; i++) { 
		if (this->stopRadio[i]->isChecked()) {  
			this->ser_stop_bits = (ser_stop_bits_t)i;
			break;
		} 
	}
	
	// Save checkboxes:
	this->ser_carrier_detect = ui->carrierCheck->checkState() / 2;
	this->ser_parity_check   = ui->parityCheck->checkState() / 2;


	this->ser_port = ui->portCmb->currentIndex();
	
	// Ok, all saved, let close the dialog
	emit this->close();
}

void SettingsTabSerialPort::restore_settings() {
		ui->baudrateCmb->setCurrentIndex(ui->baudrateCmb->findText(QString::number(this->ser_baud_rate)));
		

		this->bitsRadio[this->ser_data_bits-5]->setChecked(true);
		this->stopRadio[this->ser_stop_bits]->setChecked(true);
		
		// Set the comboBox
		ui->parityCmb->setCurrentIndex(this->ser_parity);
		ui->flowCmb->setCurrentIndex(this->ser_flow_control);
		
		ui->carrierCheck->setCheckState((Qt::CheckState) (2 * ((int)this->ser_carrier_detect)));	// 0 Unchecked 2 Checked
		ui->parityCheck->setCheckState((Qt::CheckState) (2 * ((int)this->ser_parity_check)));		// 0 Unchecked 2 Checked
		
		ui->portCmb->clear();

		for(int i=0; i < this->ser_ports_available.size(); i++) {
			ui->portCmb->addItem(this->ser_ports_available[i], i);
		}
		if(ser_port > 0)
			ui->portCmb->setCurrentIndex(ser_port);
}

