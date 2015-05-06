#ifndef GUI_SETTINGSDIALOG_H
#define GUI_SETTINGSDIALOG_H

#include <QtCore/QtGlobal>
#include <QtWidgets/QDialog>

namespace Ui {
    class Dialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private:
    Ui::Dialog *ui;

};

#endif