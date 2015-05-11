#ifndef GUI_SETTINGSDIALOG_H
#define GUI_SETTINGSDIALOG_H

#include <QShowEvent>
#include <QtCore/QtGlobal>
#include <QRadioButton>
#include <QtWidgets/QDialog>

namespace Ui {
    class Dialog;
}


typedef enum {
	ONE=0,
	ONE_HALF,
	TWO
} ser_stop_bits_t;

typedef enum {
	NO_PARITY=0,
	ODD,
	EVEN,
	MARK,
	SPACE
} ser_parity_t;

typedef enum {
	NO_FC=0,
	XON_XOFF,
	HARDWARE
} ser_flow_control_t;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

	// Settings - SERIAL:
	const QString& get_ser_port()				const { return this->ser_port; }
	int get_ser_baud_rate() 					const { return this->ser_baud_rate; }
	unsigned char get_ser_data_bits()			const { return this->ser_data_bits; }
	ser_stop_bits_t get_ser_stop_bits()			const { return this->ser_stop_bits; }
	ser_parity_t get_ser_parity() 				const { return this->ser_parity; }
	ser_flow_control_t get_ser_flow_control() 	const { return this->ser_flow_control; }
	bool get_ser_carrier_detect() 				const { return this->ser_carrier_detect; }
	bool get_ser_parity_check() 				const { return this->ser_parity_check; }

protected:
	virtual void showEvent(QShowEvent * event);	// overridden

private slots:
	void save_settings();


private:
	
	void set_signal_slots();

    Ui::Dialog *ui;
    
    // Settings - SERIAL:
	QString ser_port;
	int ser_baud_rate;
	unsigned char ser_data_bits;
	ser_stop_bits_t ser_stop_bits;
	ser_parity_t ser_parity;	// 'N', 'O', 'E', 'M', 'S'
	ser_flow_control_t ser_flow_control;	//  'N', 'X', 'H'
	bool ser_carrier_detect;
	bool ser_parity_check;

	QRadioButton **bitsRadio;
	QRadioButton **stopRadio;

};

#endif