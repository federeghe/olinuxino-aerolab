#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QtWidgets/QMainWindow>
#include "settingsdialog.hpp"
#include "rawserialtab.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connect_to_serial();
    void putRawData();
private:

    void set_signal_slots();

    Ui::MainWindow *ui;
    SettingsDialog *settings;
	RawSerialTab *rawSerial;


};

#endif