#ifndef NEWHERODIALOG_H
#define NEWHERODIALOG_H

#include <QDialog>

namespace Ui {
class newHeroDialog;
}

class newHeroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newHeroDialog(QWidget *parent = 0);
    ~newHeroDialog();

private:
    Ui::newHeroDialog *ui;
};

#endif // NEWHERODIALOG_H
