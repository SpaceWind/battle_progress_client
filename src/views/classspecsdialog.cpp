#include <QTimer>
#include "classspecsdialog.h"
#include "ui_classspecsdialog.h"

classSpecsDialog::classSpecsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classSpecsDialog)
{
    ui->setupUi(this);
}

classSpecsDialog::classSpecsDialog(int str, int dex, int mag, int intellect, int tra, int vel, int hp, int mana, QWidget *parent)
    : QDialog(parent), ui(new Ui::classSpecsDialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(str);
    ui->spinBox_2->setValue(dex);
    ui->spinBox_3->setValue(mag);
    ui->spinBox_4->setValue(intellect);
    ui->spinBox_5->setValue(tra);
    ui->spinBox_6->setValue(vel);
    ui->spinBox_7->setValue(hp);
    ui->spinBox_8->setValue(mana);
    updateBalance(0);
}

classSpecsDialog::~classSpecsDialog()
{
    delete ui;
}

void classSpecsDialog::updateBalance(int v)
{
    balance = v;
    balance = 0;
    balance += ui->spinBox->value();
    balance += ui->spinBox_2->value();
    balance += ui->spinBox_3->value();
    balance += ui->spinBox_4->value();
    balance += ui->spinBox_5->value();
    balance += ui->spinBox_6->value();
    balance += ui->spinBox_7->value()/5;
    balance += ui->spinBox_8->value()/5;

    ui->lineEdit->setText(QString::number(balance));
    if (balance < 3 && balance > -3)
    {
        ui->lineEdit_2->setStyleSheet("background-color: #99FF99;");
        ui->lineEdit_2->setText("Класс балансен!");
    }
    else if (balance <=-3)
    {
        ui->lineEdit_2->setStyleSheet("background-color: #999999;");
        ui->lineEdit_2->setText("Класс слшиком слаб!");
    }
    else
    {
        ui->lineEdit_2->setStyleSheet("background-color: #FF9999;");
        ui->lineEdit_2->setText("Класс слшиком силен!");
    }
}

void classSpecsDialog::serializeToString()
{
    data = "";
    data += "str: " + ui->spinBox->text()+";";
    data += "dex: " + ui->spinBox_2->text() + ";";
    data += "mag: " + ui->spinBox_3->text() + ";";
    data += "int: " + ui->spinBox_4->text() + ";";
    data += "tra: " + ui->spinBox_5->text() + ";";
    data += "vel: " + ui->spinBox_6->text() + ";";
    data += "hp: " + ui->spinBox_7->text() + ";";
    data += "mana: " + ui->spinBox_8->text();

}

void classSpecsDialog::on_spinBox_valueChanged(int arg1)
{
    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_2_valueChanged(int arg1)
{

    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_3_valueChanged(int arg1)
{

    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_4_valueChanged(int arg1)
{

    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_5_valueChanged(int arg1)
{

    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_6_valueChanged(int arg1)
{

    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_7_valueChanged(int arg1)
{
    updateBalance(arg1);
}

void classSpecsDialog::on_spinBox_8_valueChanged(int arg1)
{

    updateBalance(arg1);
}

void classSpecsDialog::on_pushButton_clicked()
{
    updateBalance(0);
    serializeToString();
    accept();
}

void classSpecsDialog::on_pushButton_2_clicked()
{
    reject();
}
