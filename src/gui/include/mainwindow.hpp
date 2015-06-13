#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QtWidgets/QMainWindow>
#include "settingsdialog.hpp"
#include "rawserialtab.hpp"

namespace Ui {
    class MainWindow;
}

/*! This class is the QMainWindow of our application.
 *  You should create only once of this.
 */
 
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! The constructor. Remeber: you have to call a 
     *  'show' method in order to see the window.
     * This method initializes also all submodule, like
     * settings, serial tab, etc.
     */
    explicit MainWindow(QWidget *parent = 0);
    
    /*! The destructor, currently, it doesn't do anything
     */
    ~MainWindow();

private slots:
    void connect_to_serial();

private:

    void set_signal_slots();

    Ui::MainWindow *ui;
    SettingsDialog *settings;
	RawSerialTab *raw_serial;

};

#endif