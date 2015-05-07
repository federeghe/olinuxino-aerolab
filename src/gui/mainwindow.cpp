#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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