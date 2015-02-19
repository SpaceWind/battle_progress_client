#include "mainwindow.h"
#include "admincontrolform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    adminControlForm ad;
    if (w.exit)
        return 0;
    w.showMaximized();
    ad.show();

    return a.exec();
}
