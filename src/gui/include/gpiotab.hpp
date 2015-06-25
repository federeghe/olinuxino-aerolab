#include <QWidget>
#include <QTimer>


namespace A20 {
	class GPIO_input;
	class GPIO_output;
}

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
    void changedTimer();
	void GPIOOutput();

private:
    Ui::GPIOTab *ui;
    A20::GPIO_input* gpio_in;
	A20::GPIO_output* gpio_out;


	QTimer *timer_update;
};
