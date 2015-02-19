#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginregisterdialog.h"
#include "admincontrolform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoginRegisterDialog diag;
    if (diag.exec())
    {
        ui->status->setText("Server: "+diag.getServerURL()+ " API KEY: " + diag.getKey() +
                            " Hero: " + diag.getHeroName() + " HeroHash: " + diag.getHeroHash());
        exit = false;
    }
    else
        exit = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}
