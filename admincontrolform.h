#ifndef ADMINCONTROLFORM_H
#define ADMINCONTROLFORM_H

#include <QWidget>

namespace Ui {
class adminControlForm;
}

class adminControlForm : public QWidget
{
    Q_OBJECT

public:
    explicit adminControlForm(QWidget *parent = 0);
    ~adminControlForm();

private slots:
    void on_pushButton_6_clicked();

private:
    Ui::adminControlForm *ui;
};

#endif // ADMINCONTROLFORM_H
