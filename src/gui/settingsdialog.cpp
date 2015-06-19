#include <QtWidgets/QWidget>
#include <QDebug>
#include "settingsdialog.hpp"
#include "settingstabserialport.hpp"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog( std::vector<SettingsTab*> st, QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->set_signal_slots();
    
    settingsTab = st; // Copy the settings tab pointers
    for (auto s : st) {
        ui->tabWidget->addTab(s, tr(s->get_name()));
    }
}

SettingsDialog::~SettingsDialog()
{
    // We have to delete all settings tab
    for (auto tab : this->settingsTab) {
        delete tab;
    }
}

void SettingsDialog::save_settings() {

    // Call save for every tab
    for (auto s : this->settingsTab) {
        s->save_settings();
    }
    // Ok, all saved, let close the dialog
    emit this->close();
}

void SettingsDialog::showEvent(QShowEvent * event) {
    
    if (!event->spontaneous()) {
        // Ok, call restore to every tab:
        // we have reopen the window so we need to restore
        // all settings
        for (auto s : this->settingsTab) {
            s->restore_settings();
          }

    }
    QDialog::showEvent(event);    // let's call the superclass method
}

void SettingsDialog::set_signal_slots()
{
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));        // The data will be restored at next
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(save_settings()));
}