#ifndef GUI_SETTINGSDIALOG_H
#define GUI_SETTINGSDIALOG_H

#include <QShowEvent>
#include <QtCore/QtGlobal>
#include <QRadioButton>
#include <QtWidgets/QDialog>
#include <vector>

#include "settingstab.hpp"

namespace Ui {
    class Dialog;
}


class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(std::vector <SettingsTab*> st, QWidget *parent = 0);
    ~SettingsDialog();

protected:
    virtual void showEvent(QShowEvent * event);    // overridden

private slots:
    void save_settings();


private:

	std::vector<SettingsTab *> settingsTab;	// A list of settings tab
   
    void set_signal_slots();

    Ui::Dialog *ui;

};

#endif