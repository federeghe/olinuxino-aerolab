#include <QtWidgets/QWidget>
#include <QDebug>
#include "settingsdialog.hpp"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QStringList ports_available, QWidget *parent) : QDialog(parent), ui(new Ui::Dialog),

    ser_ports_available(ports_available),
    // Default values for serial port
    ser_port(-1), ser_baud_rate(9600), ser_data_bits(8), ser_stop_bits(ONE), ser_parity(NO_PARITY),
    ser_flow_control(XON_XOFF), ser_carrier_detect(false), ser_parity_check(false)

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

    // Save combobox values:
    this->ser_baud_rate     = ui->baudrateCmb->currentText().toInt();
    this->ser_parity        = (ser_parity_t) ui->parityCmb->currentIndex();
    this->ser_flow_control    = (ser_flow_control_t) ui->flowCmb->currentIndex();

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

void SettingsDialog::showEvent(QShowEvent * event) {
    
    if (!event->spontaneous()) {
        ui->baudrateCmb->setCurrentIndex(ui->baudrateCmb->findText(QString::number(this->ser_baud_rate)));
        

        this->bitsRadio[this->ser_data_bits-5]->setChecked(true);
        this->stopRadio[this->ser_stop_bits]->setChecked(true);
        
        // Set the comboBox
        ui->parityCmb->setCurrentIndex(this->ser_parity);
        ui->flowCmb->setCurrentIndex(this->ser_flow_control);
        
        ui->carrierCheck->setCheckState((Qt::CheckState) (2 * ((int)this->ser_carrier_detect)));    // 0 Unchecked 2 Checked
        ui->parityCheck->setCheckState((Qt::CheckState) (2 * ((int)this->ser_parity_check)));        // 0 Unchecked 2 Checked
        
        ui->portCmb->clear();

        for(int i=0; i < this->ser_ports_available.size(); i++) {
            ui->portCmb->addItem(this->ser_ports_available[i], i);
        }
        if(ser_port > 0)
            ui->portCmb->setCurrentIndex(ser_port);
    }
    QDialog::showEvent(event);    // let's call the superclass method
}

void SettingsDialog::set_signal_slots()
{
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(save_settings()));
}