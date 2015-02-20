#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admincontrolform.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showEvent(QShowEvent *);
    ~MainWindow();
    bool exit;
public slots:
    void createAdminWindow();

private:
    Ui::MainWindow *ui;

    currentUserInfo accountInfo;

    adminControlForm * adminForm;
};

#endif // MAINWINDOW_H
