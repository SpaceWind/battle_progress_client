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

struct SpellDescriptor
{
    static SpellDescriptor fromString(QString str);
    QString toString();
    QString spell_name;
    QString spell_class;
    QString cd;
    QString cost;
    QStringList effects;
    QString req;
    QString level_scales;
    QString stat_scales;
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
    void newSpecsAction();
    void newSpecsResponse(QByteArray response);

    void newFactionAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp);
    void newFactionResponse(QByteArray response);

    void saveDescAction(QString name, QString item);
    void saveDescResponse(QByteArray response);
    void resaveDesc();

    void getClassInfoAction(QString className);
    void getClassInfoResponse(QByteArray response);
    void getNextClassSpecs();
    void getClassSpecsAction(QString className);
    void getClassSpecsResponse(QByteArray response);

    void getFactionInfoAction(QString factionName);
    void getFactionInfoResponse(QByteArray response);

    void getFactionRelationsAction(QString factionName);
    void getFactionRelationsResponse(QByteArray response);
    QList<RelationDesc> compileRelations(QStringList items, QStringList hostile, QStringList friendly);
    void nextFactionRelation();
    void renderFactionRelations();

    void getClassRelationsAction(QString className);
    void getClassRelationsResponse(QByteArray response);
    void nextClassRelation();
    void renderClassRelations();

    void saveFactionRelationsAction(QString factionName);
    void saveFactionRelationsResponse(QByteArray response);
    void nextFactionSave();

    void saveClassRelationsAction(QString className);
    void saveClassRelationsResponse(QByteArray response);
    void nextClassSave();

    void loadSpellsForClassAction();
    void loadSpellsForClassResponse(QByteArray response);

    void saveSpellForClassAction();
    void saveSpellForClassResponse(QByteArray response);

    void destroySpellAction();
    void destroySpellResponse(QByteArray response);


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

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_spells_combobox_currentIndexChanged(const QString &arg1);

    void on_spell_effect_list_currentRowChanged(int currentRow);

    void on_new_effect_clicked();

    void on_update_effect_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_spell_class_combobox_currentIndexChanged(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

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

    QHash<QString, QString> spells;
    QHash<QString, SpellDescriptor> spell_descriptors;
};


#endif // ADMINCONTROLFORM_H
