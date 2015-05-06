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

	// Settings - SERIAL:
	const QString& get_ser_port()		const { return this->ser_port; }
	int get_ser_baud_rate() 			const { return this->ser_baud_rate; }
	unsigned char get_ser_data_bits()	const { return this->ser_data_bits; }
	unsigned char get_ser_stop_bits()	const { return this->ser_stop_bits; }
	char get_ser_parity() 				const { return this->ser_parity; }
	char get_ser_flow_control() 		const { return this->ser_flow_control; }
	bool get_ser_carrier_detect() 		const { return this->ser_carrier_detect; }
	bool get_ser_parity_check() 		const { return this->ser_parity_check; }

private:

	void set_signal_slots();

    Ui::MainWindow *ui;
    SettingsDialog *settings;

	// Settings - SERIAL:
	QString ser_port;
	int ser_baud_rate;
	unsigned char ser_data_bits;
	unsigned char ser_stop_bits;	// 1 15 2 (omit dot '.' in 1.5)
	char ser_parity;	// 'N', 'O', 'E', 'M', 'S'
	char ser_flow_control;	//  'N', 'X', 'H'
	bool ser_carrier_detect;
	bool ser_parity_check;

};

#endif