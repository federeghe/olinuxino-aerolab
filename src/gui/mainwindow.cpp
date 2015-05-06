#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), 

	// Default value for serial port
	ser_port(""), ser_baud_rate(9600), ser_data_bits(8), ser_stop_bits(1), ser_parity('N'),
	ser_flow_control('X'), ser_carrier_detect(false), ser_parity_check(false)

{
    ui->setupUi(this);

    this->settings = new SettingsDialog();
    
    this->set_signal_slots();
}

MainWindow::~MainWindow()
{

}

void MainWindow::set_signal_slots()
{
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->settingsButton, SIGNAL(clicked()), this->settings, SLOT(exec()));
}