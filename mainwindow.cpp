#include <QShowEvent>
#include <QTimer>
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
        accountInfo.apikey = diag.getKey();
        accountInfo.group = diag.getGroup();
        accountInfo.server = diag.getServerURL();
        accountInfo.heroHash = diag.getHeroHash();
        accountInfo.heroName = diag.getHeroName();
        accountInfo.login = diag.getLogin();
        ui->status->setText(accountInfo.toString());
        exit = false;
    }
    else
        exit = true;
    adminForm = 0;
}

void MainWindow::showEvent(QShowEvent *)
{
    if (adminForm)
        return;
    QTimer::singleShot(0,this,SLOT(createAdminWindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createAdminWindow()
{
    if (accountInfo.group == "admins")
    {
        adminForm = new adminControlForm();
        adminForm->setWindowModality(Qt::WindowModal);
        adminForm->show();
        adminForm->setFocus();
        adminForm->setUser(accountInfo);
        this->hide();
    }
}
