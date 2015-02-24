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
    void searchHeroesForLoginAction(QString login, QString apikey);
    void searchHeroesForLoginResponse(QByteArray response);

    void searchRacesAction();
    void searchRacesResponse(QByteArray response);

    void searchFactionsActions();
    void searchFactionsResponse(QByteArray response);

    void newClassAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp);
    void newFactionAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp);
    void newClassResponse(QByteArray response);
    void newFactionResponse(QByteArray response);

    void saveDescAction(QString name, QString item);
    void saveDescResponse(QByteArray response);
    void resaveDesc();

    void on_pushButton_clicked();

    void on_found_heroes_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::adminControlForm *ui;

    currentUserInfo currentUser;
    GameServer * server;

    QHash<QString, heroDescriptor_Min> foundHeroes;

    QStringList races;
    QStringList factions;
    int lastDescIndex;

    QString lastDescName, lastDescItem;
};

#endif // ADMINCONTROLFORM_H
