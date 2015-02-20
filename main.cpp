#include "mainwindow.h"
#include "admincontrolform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if (w.exit)
        return 0;
    w.showMaximized();

    return a.exec();
}
