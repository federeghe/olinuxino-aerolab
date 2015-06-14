#include <QApplication>
#include <QTextStream>

#include "mainwindow.hpp"

/*! The entrypoint of our application.
 */
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // Display the main window
    MainWindow *w = new MainWindow();
    w->showFullScreen();

    // Exec the main QT application
    return a.exec();
}
