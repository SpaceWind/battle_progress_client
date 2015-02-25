#ifndef ADMINCONTROLFORM_H
#define ADMINCONTROLFORM_H

#include <QWidget>
#include <QComboBox>
#include <QHash>
#include "helpers.h"
#include "gameserver.h"

namespace Ui {
class adminControlForm;
}


struct RelationDesc
{
    enum Relation {HOSTILE, NEUTRAL, FRIENDLY};
    QString factionName;
    Relation relation;
    static Relation getRelationByString(QString desc);

};

class adminControlForm : public QWidget
{
    Q_OBJECT

public:
    explicit adminControlForm(QWidget *parent = 0);
    void setUser(currentUserInfo& info);
    ~adminControlForm();


    //--------------public Methods--------------------------------------------------------------------------

private slots:

    //-----------------------Actions and Responsers---------------------------------------------------------------
    void searchHeroesForLoginAction(QString login, QString apikey);
    void searchHeroesForLoginResponse(QByteArray response);

    void searchRacesAction();
    void searchRacesResponse(QByteArray response);

    void searchFactionsAction();
    void searchFactionsResponse(QByteArray response);

    void newClassAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp);
    void newClassResponse(QByteArray response);

    void newFactionAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp);
    void newFactionResponse(QByteArray response);

    void saveDescAction(QString name, QString item);
    void saveDescResponse(QByteArray response);
    void resaveDesc();

    void getClassInfoAction(QString className);
    void getClassInfoResponse(QByteArray response);

    void getFactionInfoAction(QString factionName);
    void getFactionInfoResponse(QByteArray response);

    void getFactionRelationsAction(QString factionName);
    void getFactionRelationsResponse(QByteArray response);
    QList<RelationDesc> compileRelations(QStringList items, QStringList hostile, QStringList friendly);
    void nextFactionRelation();
    void renderFactionRelations();

    void saveFactionRelationsAction(QString factionName);
    void saveFactionRelationsResponse(QByteArray response);
    void nextFactionSave();



    //----------------------Handlers-----------------------------------------------------------------------------
    void on_pushButton_clicked();

    void on_found_heroes_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_faction_reload_clicked();

    void on_class_reload_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::adminControlForm *ui;

    currentUserInfo currentUser;
    GameServer * server;

    QHash<QString, heroDescriptor_Min> foundHeroes;

    QStringList races;
    QStringList factions;
    int lastDescIndex;

    QString lastDescName, lastDescItem;
    QString lastClassInfoName, lastFactionInfoName;

    QHash<QString, QComboBox*> factionTableItems;
    QHash<QString, QComboBox*> classTableItems;
    QHash<QString, QList<RelationDesc> > factionRelations;
    QHash<QString, QList<RelationDesc> > classRelations;
};

#endif // ADMINCONTROLFORM_H
