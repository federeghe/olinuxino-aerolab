#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QScrollBar>
#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	raw_serial = new RawSerialTab();
	ui->tabWidget->addTab(raw_serial, tr("Raw Serial"));

    // Create the settings tab:
    std::vector <SettingsTab *> st;
	st.push_back(raw_serial->get_settings_tab());
	
    
    this->settings = new SettingsDialog(st);	// st is cleared by settingsdialog
    
    this->set_signal_slots();
}

MainWindow::~MainWindow()
{

}

void MainWindow::connect_to_serial() {
    static bool connected = false;
    
    if (connected) {
    	// If serial disconnection successful, let connected
    	// become false.
		connected = ! this->raw_serial->serial_disconnect();
    } else {
    	// If serial connection successful, let connected
    	// become true.
		connected = this->raw_serial->serial_connect();
    }
    
    // Change the connection string in the button
    ui->connectButton->setText( connected ? "Disconnect" : "Connect" ); 
}

void MainWindow::set_signal_slots()
{
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->settingsButton, SIGNAL(clicked()), this->settings, SLOT(exec()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connect_to_serial()));
    
}