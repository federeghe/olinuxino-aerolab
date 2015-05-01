#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // Display the main window
    MainWindow w;
    w.show();

    // Exec the main QT application
    return a.exec();
}
