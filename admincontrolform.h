#ifndef ADMINCONTROLFORM_H
#define ADMINCONTROLFORM_H

#include <QWidget>
#include <QHash>
#include "helpers.h"
#include "gameserver.h"

namespace Ui {
class adminControlForm;
}

class adminControlForm : public QWidget
{
    Q_OBJECT

public:
    explicit adminControlForm(QWidget *parent = 0);
    void setUser(currentUserInfo& info);
    ~adminControlForm();

private slots:
    void searchHeroesForLoginResponse(QByteArray response);
    void on_pushButton_clicked();

private:
    Ui::adminControlForm *ui;

    currentUserInfo currentUser;
    GameServer * server;

    QHash<QString, heroDescriptor_Min> foundHeroes;
};

#endif // ADMINCONTROLFORM_H
