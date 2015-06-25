#include "gpiotab.hpp"
#include "ui_gpiotab.h"
#include "A20-gpio.hpp"

#include <iostream>

GPIOTab::GPIOTab() : QWidget(0), ui(new Ui::GPIOTab) {

    ui->setupUi(this);

	// 500 msec default
	ui->te_refresh_time->setDateTime(QDateTime::fromString("500","zzz"));

	try {
		// Init the A20 GPIO subsystem
		A20::GPIO::init();
		// One input
		this->gpio_in = A20::GPIO::get_input(256,A20::PULL_UP);
		this->gpio_out = A20::GPIO::get_output(257);
		// And one output
		
		
		// Start the timer to update the input checkbox
		timer_update = new QTimer(this);
		connect(timer_update, SIGNAL(timeout()), this, SLOT(updateGPIOData()));
		timer_update->setSingleShot(false);	// Always running timer
		timer_update->start(500);

		// Now I can connect the timeEdit		
		connect(ui->te_refresh_time, SIGNAL(timeChanged(QTime)), this, SLOT(changedTimer()));
		connect(ui->cb_output, SIGNAL(clicked()), this, SLOT(GPIOOutput()));
		
		ui->lbl_na->setVisible(false);
		
	} catch(...) {
		std::cout << "GPIO Not available." << std::endl;
	}
	
}

GPIOTab::~GPIOTab() {
		A20::GPIO::free(256);
		A20::GPIO::free(257);
}


void GPIOTab::GPIOOutput() {
	bool enable_out = this->ui->cb_output->checkState() / 2;
	this->gpio_out->set(enable_out);
}

void GPIOTab::changedTimer() {
	// Received request of change the time interval. I update only for minutes and seconds.
	QTime t = ui->te_refresh_time->dateTime().time();
	timer_update->setInterval(t.msec() + t.second()*1000 + t.minute()*60*1000);
}


void GPIOTab::updateGPIOData() {

	bool value = gpio_in->get();
	this->ui->cb_input->setCheckState((Qt::CheckState) (2 * ((int)value))); 

}
