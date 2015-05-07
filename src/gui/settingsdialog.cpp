#include <QtWidgets/QWidget>
#include "settingsdialog.hpp"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog),

	// Default value for serial port
	ser_port(""), ser_baud_rate(9600), ser_data_bits(8), ser_stop_bits(ONE), ser_parity('N'),
	ser_flow_control('X'), ser_carrier_detect(false), ser_parity_check(false)

{
    ui->setupUi(this);
    this->set_signal_slots();
    
    this->bitsRadio  = new QRadioButton*[5] {ui->bits5Radio, ui->bits6Radio, ui->bits7Radio, ui->bits8Radio, ui->bits9Radio };
    this->stopRadio  = new QRadioButton*[3] {ui->stopbits1Radio, ui->stopbits15Radio, ui->stopbits2Radio };
}

SettingsDialog::~SettingsDialog()
{
	delete[] this->bitsRadio;
	delete[] this->stopRadio;
}

void SettingsDialog::save_settings() {

}

void SettingsDialog::showEvent(QShowEvent * event) {
	
	if (!event->spontaneous()) {
		ui->baudrateCmb->setCurrentIndex(ui->baudrateCmb->findText(QString::number(this->ser_baud_rate)));
		

		this->bitsRadio[this->ser_data_bits-5]->setChecked(true);
		this->stopRadio[this->ser_stop_bits]->setChecked(true);
		
		ui->parityCmb->setCurrentIndex(this->ser_parity);
		ui->flowControlCmb->setCurrentIndex(this->ser_flow_control);
		//ui->datastopsCmb->setCurrentIndex(ui->baudrateCmb->findText(QString::number(this->ser_baud_rate)));
		
		ui->carrierCheck->setCheckState((Qt::CheckState) (2 * ((int)this->ser_carrier_detect)));	// 0 Unchecked 2 Checked
		ui->parityCheck->setCheckState((Qt::CheckState) (2 * ((int)this->ser_parity_check)));		// 0 Unchecked 2 Checked
	}
	QDialog::showEvent(event);	// let's call the superclass method
}

void SettingsDialog::set_signal_slots()
{
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(save_settings()));
}