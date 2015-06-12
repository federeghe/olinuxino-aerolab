#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QtWidgets/QMainWindow>
#include "settingsdialog.hpp"
#include "serialport.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SerialPort *sp, QWidget *parent = 0);
    ~MainWindow();

private slots:
####void connect_to_serial();
####void putRawData();
private:

####void set_signal_slots();

    Ui::MainWindow *ui;
    SettingsDialog *settings;
    SerialPort *serialPort;

};

#endif