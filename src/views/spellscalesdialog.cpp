#include "spellscalesdialog.h"
#include "ui_spellscalesdialog.h"

/*SpellScalesDialog::SpellScalesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpellScalesDialog)
{
    ui->setupUi(this);
}*/

SpellScalesDialog::SpellScalesDialog(QStringList effects, bool pureScales, QWidget *parent) : QDialog(parent), ui(new Ui::SpellScalesDialog)
{
    ui->setupUi(this);
    if (pureScales)
        ui->dependance_combobox->setEnabled(false);
    else
    {
        ui->dependance_combobox->addItem("STR");
        ui->dependance_combobox->addItem("DEX");
        ui->dependance_combobox->addItem("MAG");
        ui->dependance_combobox->addItem("INT");
        ui->dependance_combobox->addItem("TRA");
        ui->dependance_combobox->addItem("VEL");
        ui->dependance_combobox->addItem("HP");
        ui->dependance_combobox->addItem("MANA");
    }
    if (!effects.isEmpty())
    {
        foreach(const QString& effect, effects)
            ui->effect_combobox->addItem(effect);
    }
}

SpellScalesDialog::~SpellScalesDialog()
{
    delete ui;
}

void SpellScalesDialog::on_pushButton_clicked()
{
    QString scale = QString::number(ui->scale_value->value()).mid(0,4);
    if (ui->dependance_combobox->currentText() != "")
        if (ui->scale_value->value() != 0.)
            scale += "*" + ui->dependance_combobox->currentText();

    ui->scale_list->addItem(scale);
    if (scales[ui->effect_combobox->currentText()] == "")
        scales[ui->effect_combobox->currentText()] = scale;
    else
        scales[ui->effect_combobox->currentText()] = scales[ui->effect_combobox->currentText()] + "," + scale;
}

void SpellScalesDialog::on_pushButton_2_clicked()
{
    delete ui->scale_list->takeItem(ui->scale_list->currentRow());
    QString newScale = "";
    for (int i=0; i<ui->scale_list->count(); i++)
    {
        newScale += ui->scale_list->item(i)->text();
        if (i != ui->scale_list->count()-1)
            newScale += ",";
    }
    scales[ui->effect_combobox->currentText()] = newScale;
}

void SpellScalesDialog::on_pushButton_3_clicked()
{

    for(int i=0; i<ui->effect_combobox->count(); i++)
    {
        QString effect = ui->effect_combobox->itemText(i);
        serializedScale += scales[effect].replace(","," ");
        if (i!=ui->effect_combobox->count()-1)
            serializedScale += ",";
    }
    accept();
}

void SpellScalesDialog::on_pushButton_4_clicked()
{
    reject();
}

void SpellScalesDialog::on_effect_combobox_currentIndexChanged(const QString &arg1)
{
    ui->scale_list->clear();
    QString currentScale;
    if (scales.contains(arg1))
        currentScale = scales[arg1];
    if (currentScale != "")
    {
        QStringList scaleTokens = currentScale.split(",");
        foreach(const QString& token, scaleTokens)
            ui->scale_list->addItem(token);
    }
}
