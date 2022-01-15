// Starting Point of application

// QApplication for running app
#include<QApplication>

// Main window class
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // Instance of app and window
    QApplication tickle(argc, argv);
    MainWindow gameWindow;

    // Set the game window title
    gameWindow.setWindowTitle("Tickle");

    // Execute the app
    gameWindow.show();
    return tickle.exec();
}
