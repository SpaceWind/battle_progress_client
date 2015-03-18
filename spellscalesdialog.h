#ifndef SPELLSCALESDIALOG_H
#define SPELLSCALESDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class SpellScalesDialog;
}

class SpellScalesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpellScalesDialog(QStringList effects, bool pureScales=true, QWidget *parent = 0);
    ~SpellScalesDialog();

private:
    Ui::SpellScalesDialog *ui;
};

#endif // SPELLSCALESDIALOG_H
