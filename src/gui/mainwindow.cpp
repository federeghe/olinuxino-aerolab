#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QScrollBar>
#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	rawSerial = new RawSerialTab();
	ui->tabWidget->addTab(rawSerial, tr("Raw Serial"));

    // Create the settings tab:
    std::vector <SettingsTab *> st;
	st.push_back(rawSerial->get_settings_tab());
	
    
    this->settings = new SettingsDialog(st);	// st is cleared by settingsdialog
    
    this->set_signal_slots();
}

MainWindow::~MainWindow()
{

}

void MainWindow::connect_to_serial() {
    static bool connected = false;
/*
    if (connected) {
        this->serialPort->close();
        ui->connectButton->setText("Connect");
        ui->rawDataEdit->append("\n\nDISCONNECTED!\n");
        connected = false;
        return;
    }

    int selected = this->settings->get_ser_port();
    if (selected >= 0) {
        ui->rawDataEdit->append(this->serialPort->get_list()[selected] + ": connecting...\n");
        
        if ( this->serialPort->open_port( selected,
                                this->settings->get_ser_baud_rate(),
                                this->settings->get_ser_data_bits(),
                                this->settings->get_ser_stop_bits(),
                                this->settings->get_ser_parity(),
                                this->settings->get_ser_flow_control(),
                                this->settings->get_ser_carrier_detect(),
                                this->settings->get_ser_parity_check()                                
                                )
                                
            ) {
                ui->rawDataEdit->append("++ CONNECTED!\n\n");
                ui->connectButton->setText("Disconnect");
                connected = true;
            } else {
                ui->rawDataEdit->append("-- UNABLE TO CONNECT.\n\n");
            }
    }*/
}

void MainWindow::putRawData()
{
/*    // Read data
    QByteArray data = this->serialPort->readRawData();

    // Add text
    ui->rawDataEdit->append(QString(data));

    // Then scroll to down
    QScrollBar *bar = ui->rawDataEdit->verticalScrollBar();
    bar->setValue(bar->maximum());*/
}

void MainWindow::set_signal_slots()
{
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->settingsButton, SIGNAL(clicked()), this->settings, SLOT(exec()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connect_to_serial()));
    
}