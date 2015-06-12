#include <QApplication>
#include <QTextStream>

#include "mainwindow.hpp"
#include "serialport.hpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

	// Start serial port handler
	SerialPort sp;

    // Display the main window
    MainWindow w(&sp);
    w.showFullScreen();

    // Exec the main QT application
    return a.exec();
}
