#include "mainwindow.h"

#include <QApplication>

// Main Application
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Tickle");
    window.show();
    return app.exec();
}
