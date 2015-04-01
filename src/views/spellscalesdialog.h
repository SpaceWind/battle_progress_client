#ifndef SPELLSCALESDIALOG_H
#define SPELLSCALESDIALOG_H

#include <QDialog>
#include <QStringList>
#include <Qhash>

namespace Ui {
class SpellScalesDialog;
}

class SpellScalesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpellScalesDialog(QStringList effects, bool pureScales=true, QWidget *parent = 0);
    QString getScale(){return serializedScale;}
    ~SpellScalesDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_effect_combobox_currentIndexChanged(const QString &arg1);

private:
    Ui::SpellScalesDialog *ui;
    QHash<QString, QString> scales;
    QString serializedScale;
};

#endif // SPELLSCALESDIALOG_H
