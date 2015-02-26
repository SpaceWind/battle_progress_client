#include "newherodialog.h"
#include "ui_newherodialog.h"

newHeroDialog::newHeroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newHeroDialog)
{
    ui->setupUi(this);
}

newHeroDialog::~newHeroDialog()
{
    delete ui;
}
