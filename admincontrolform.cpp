#include "admincontrolform.h"
#include "ui_admincontrolform.h"

adminControlForm::adminControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminControlForm)
{
    ui->setupUi(this);
}

adminControlForm::~adminControlForm()
{
    delete ui;
}

void adminControlForm::on_pushButton_6_clicked()
{
    ui->tableView->setC
}
