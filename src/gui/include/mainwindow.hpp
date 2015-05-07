#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QtWidgets/QMainWindow>
#include "settingsdialog.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

	void set_signal_slots();

    Ui::MainWindow *ui;
    SettingsDialog *settings;

};

#endif