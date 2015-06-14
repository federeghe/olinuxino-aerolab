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

/*! The class for dialog of settings. It's a Dialog with a tab pane
 *  and each tab is added via parameters passed to constructor.
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
	/*! Constructor for setting dialog. You have to pass the list of settings tab
	 *  and, in case, the parent window. The second parameter is not generally necessary.
	 *  NOTE: the destructor delete also all settingstab present in vector passed.
	 */
    explicit SettingsDialog(std::vector <SettingsTab*> st, QWidget *parent = 0);
    ~SettingsDialog();

protected:
	/*! Overridden method of QDialog
	 * @override
	 */
    virtual void showEvent(QShowEvent * event);

private slots:
    void save_settings();


private:

	std::vector<SettingsTab *> settingsTab;	// A list of settings tab
    Ui::Dialog *ui;
    
    void set_signal_slots();

};

#endif
