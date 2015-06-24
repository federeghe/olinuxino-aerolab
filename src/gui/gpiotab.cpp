#include "gpiotab.hpp"
#include "ui_gpiotab.h"

GPIOTab::GPIOTab() : QWidget(0), ui(new Ui::GPIOTab) {

    ui->setupUi(this);

}

GPIOTab::~GPIOTab() {

}


void GPIOTab::GPIOOutput() {};

void GPIOTab::updateGPIOData() {};
