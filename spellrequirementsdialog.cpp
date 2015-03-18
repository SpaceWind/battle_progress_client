#include "spellrequirementsdialog.h"
#include "ui_spellrequirementsdialog.h"

SpellRequirementsDialog::SpellRequirementsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpellRequirementsDialog)
{
    ui->setupUi(this);
}

SpellRequirementsDialog::~SpellRequirementsDialog()
{
    delete ui;
}

void SpellRequirementsDialog::on_pushButton_clicked()
{
    formatted = "";
    if (ui->spinBox->value())
        formatted+="s="+QString::number(ui->spinBox->value())+",";
    if (ui->spinBox_2->value())
        formatted+="d="+QString::number(ui->spinBox_2->value())+",";
    if (ui->spinBox_3->value())
        formatted+="m="+QString::number(ui->spinBox_3->value())+",";
    if (ui->spinBox_4->value())
        formatted+="i="+QString::number(ui->spinBox_4->value())+",";
    if (ui->spinBox_5->value())
        formatted+="t="+QString::number(ui->spinBox_5->value())+",";
    if (ui->spinBox_6->value())
        formatted+="v="+QString::number(ui->spinBox_6->value())+",";
    if (ui->spinBox_7->value())
        formatted+="h="+QString::number(ui->spinBox_7->value())+",";
    if (ui->spinBox_8->value())
        formatted+="ma="+QString::number(ui->spinBox_8->value());
    accept();
}

void SpellRequirementsDialog::on_pushButton_2_clicked()
{
    formatted="";
    reject();
}
