#ifndef CLASSSPECSDIALOG_H
#define CLASSSPECSDIALOG_H

#include <QDialog>
#include "helpers.h"


namespace Ui {
class classSpecsDialog;
}

class classSpecsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit classSpecsDialog(QWidget *parent = 0);
    explicit classSpecsDialog(int str, int dex, int mag, int intellect, int tra, int vel, int hp, int mana, QWidget *parent = 0);
    ~classSpecsDialog();
    QString data;

private slots:
    void updateBalance(int v);
    void serializeToString();
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_spinBox_7_valueChanged(int arg1);

    void on_spinBox_8_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::classSpecsDialog *ui;
    int balance;
    classSpecsDesc desc;
};

#endif // CLASSSPECSDIALOG_H
