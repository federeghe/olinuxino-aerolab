#include <QWidget>
//#include "logic/include/gpio.hpp"

namespace Ui {
    class GPIOTab;
}

/*! This class represent a tab for raw serial textbox in the main window
 *
 */
class GPIOTab : public QWidget {
    Q_OBJECT
public:
    
    /*! The constructor. Initialize the GPIO objects
     */
    explicit GPIOTab();
    
    /*! The destructor */
    ~GPIOTab();

private slots:

    void updateGPIOData();
	void GPIOOutput();

private:
    Ui::GPIOTab *ui;

};
