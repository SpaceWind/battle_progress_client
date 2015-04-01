#ifndef SPELLREQUIREMENTSDIALOG_H
#define SPELLREQUIREMENTSDIALOG_H

#include <QDialog>

namespace Ui {
class SpellRequirementsDialog;
}

class SpellRequirementsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpellRequirementsDialog(QWidget *parent = 0);
    QString getReq(){return formatted;}
    ~SpellRequirementsDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SpellRequirementsDialog *ui;
    QString formatted;
};

#endif // SPELLREQUIREMENTSDIALOG_H
