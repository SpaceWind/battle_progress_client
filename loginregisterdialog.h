#ifndef LOGINREGISTERDIALOG_H
#define LOGINREGISTERDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QList>
#include "gameserver.h"
#include "helpers.h"

namespace Ui {
class LoginRegisterDialog;
}

class LoginRegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginRegisterDialog(QWidget *parent = 0);
    ~LoginRegisterDialog();
    QString getKey(){return apikey;}
    QString getServerURL(){return serverUrl;}
    QString getHeroName(){return chosenHeroName;}
    QString getHeroHash(){return chosenHeroHash;}
    QString getLogin(){return login;}
    QString getGroup(){return group;}



private slots:
    void getHeroes();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void registrationResponse(QByteArray response);
    void loginResponse(QByteArray response);
    void searchHeroesResponse(QByteArray response);
    void newHeroResponse(QByteArray response);

    void checkUserResponse(QByteArray response);
    void checkUserAction(QString login);

    void pingServerAction();
    void pingServerResponse(QByteArray response);


    void on_register_server_returnPressed();

    void on_new_hero_clicked();

    void on_connect_button_clicked();

    void on_heroes_currentIndexChanged(const QString &arg1);

    void on_register_nickname_editingFinished();

    void on_pushButton_3_clicked();

private:
    Ui::LoginRegisterDialog *ui;
    GameServer * server;
    QString apikey;
    QString serverUrl;
    QString chosenHeroName;
    QString chosenHeroHash;
    QString group;
    QString login;
    QHash<QString, QString> foundHeroes;

};

#endif // LOGINREGISTERDIALOG_H
