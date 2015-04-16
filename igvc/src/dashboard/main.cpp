#include <QtGui>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow w(nullptr);
    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    return app.exec();
}
