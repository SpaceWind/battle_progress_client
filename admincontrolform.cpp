#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QTime>
#include <QTimer>
#include <QClipboard>
#include <QStyledItemDelegate>

#include "admincontrolform.h"
#include "classspecsdialog.h"
#include "spellrequirementsdialog.h"
#include "spellscalesdialog.h"
#include "ui_admincontrolform.h"

adminControlForm::adminControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminControlForm)
{
    ui->setupUi(this);
    server = 0;
    lastDescIndex = 0;

    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    ui->creature_spell_combobox->setItemDelegate(itemDelegate);
    ui->creature_type_combobox->addItem("creature");
    ui->creature_type_combobox->addItem("prefix");
    ui->creature_type_combobox->addItem("suffix");

}

void adminControlForm::setUser(currentUserInfo &info)
{
    currentUser = info;
    if (server)
        delete server;
    server = new GameServer(info.server);
    QTimer::singleShot(100,this, SLOT(searchRacesAction()));
}

adminControlForm::~adminControlForm()
{
    delete ui;
}

void adminControlForm::searchHeroesForLoginAction(QString login, QString apikey)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["login"] = login;
    params["apikey"] = apikey;

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(searchHeroesForLoginResponse(QByteArray)));

    server->call("admin heroes",params);
    ui->pushButton->setEnabled(false);
    ui->status_label->setText("Searching for heroes...");
}

void adminControlForm::searchHeroesForLoginResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!");
    else
    {
        jsonParser parser(response);
        QJsonValue status = parser.first("status");

        if (parser.getBool("success"))
        {
            QStringList hashes = parser.get("heroes[]");
            QStringList names = parser.get("names[]");
            QStringList lvls = parser.get("lvls[]");
            QStringList races = parser.get("races[]");
            QStringList factions = parser.get("factions[]");

            foundHeroes.clear();
            ui->found_heroes->clear();
            for (int i=0; i<hashes.count(); i++)
            {
                heroDescriptor_Min currentHero;
                currentHero.hash = hashes[i];
                currentHero.lvl = lvls[i].toInt();
                currentHero.race = races[i];
                currentHero.faction = factions[i];
                foundHeroes[names[i]] = currentHero;
                ui->found_heroes->addItem(names[i]);
            }
            if (hashes.count() != 0)
            {
                ui->found_heroes->setEnabled(true);
                ui->level_label->setEnabled(true);
                ui->class_combobox->setEnabled(true);
                ui->faction_combobox->setEnabled(true);
            }
            ui->status_label->setText("Success!");
        }
        else
            ui->status_label->setText("ERROR: " + status.toString("Reponse Incorrect"));
    }
    ui->pushButton->setEnabled(true);
}

void adminControlForm::searchRacesAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(searchRacesResponse(QByteArray)));

    server->call("meta classes",params);
    ui->pushButton->setEnabled(false);
    ui->status_label->setText("Searching for races...");
}

void adminControlForm::searchFactionsAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(searchFactionsResponse(QByteArray)));

    server->call("meta factions",params);
    ui->pushButton->setEnabled(false);
    ui->status_label->setText("Searching for factions...");
}

void adminControlForm::searchRacesResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!");
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            races.clear();
            races.append(parser.get("classes[]"));
            ui->class_combobox->clear();
            ui->class_combobox->addItems(races);
        }
        ui->status_label->setText(parser.first("status"));
    }
    QTimer::singleShot(500,this,SLOT(searchFactionsAction()));
}

void adminControlForm::searchFactionsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            factions.clear();
            factions.append(parser.get("factions[]"));
            ui->faction_combobox->clear();
            ui->faction_combobox->addItems(races);
        }
        ui->status_label->setText(parser.first("status"));
    }
    ui->pushButton->setEnabled(true);
}

void adminControlForm::newClassAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = apikey;
    params["person_name"] = name;
    params["lib_imp"] = imp;
    params["lib_rop"] = rop;
    params["lib_dap"] = dap;
    params["lib_vip"] = vip;
    params["lib_tvp"] = tvp;
    params["lib_prp"] = prp;

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(newClassResponse(QByteArray)));

    server->call("admin newClass",params);
    ui->status_label->setText("Saving class...");
}

void adminControlForm::newFactionAction(QString name, QString apikey, QString imp, QString rop, QString dap, QString vip, QString tvp, QString prp)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = apikey;
    params["faction_name"] = name;
    params["lib_imp"] = imp;
    params["lib_rop"] = rop;
    params["lib_dap"] = dap;
    params["lib_vip"] = vip;
    params["lib_tvp"] = tvp;
    params["lib_prp"] = prp;

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(newFactionResponse(QByteArray)));

    server->call("admin newFaction",params);
    ui->status_label->setText("Creating new faction...");
}

void adminControlForm::newClassResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        ui->status_label->setText(parser.first("status"));
        lastDescIndex = 0;
        lastDescName = ui->class_name->text();
        lastDescItem = "Class";
        QTimer::singleShot(250,this,SLOT(resaveDesc()));
    }
}

void adminControlForm::newSpecsAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }

    classSpecsDesc specs = classSpecsDesc::fromString(ui->class_specs->text());
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["class_name"] = ui->class_name->text();
    params["str"] = QString::number(specs.str);
    params["dex"] = QString::number(specs.dex);
    params["mag"] = QString::number(specs.mag);
    params["int"] = QString::number(specs.intellect);
    params["tra"] = QString::number(specs.tra);
    params["vel"] = QString::number(specs.vel);
    params["hp"] = QString::number(specs.hp);
    params["mana"] = QString::number(specs.mana);

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(newSpecsResponse(QByteArray)));

    server->call("admin class setSpecs",params);
    ui->status_label->setText("Saving specs...");
}

void adminControlForm::newSpecsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText("ERROR: "+parser.first("status"));
    }
}

void adminControlForm::newFactionResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        ui->status_label->setText(parser.first("status"));
        lastDescIndex = 0;
        lastDescName = ui->faction_name->text();
        lastDescItem = "Faction";
        QTimer::singleShot(250,this,SLOT(resaveDesc()));
    }
}

void adminControlForm::saveDescAction(QString name, QString item)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QString text;
    if (item == "Faction")
        text = ui->faction_desc->toPlainText();
    else
        text = ui->class_desc->toPlainText();
    if (lastDescIndex>= text.length())
    {
        ui->status_label->setText("OK");
        setEnabled(true);
        QTimer::singleShot(150,this,SLOT(newSpecsAction()));
        return;
    }
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    if (item == "Faction")
        params["faction_name"] = name;
    else
        params["person_name"] = name;
    int messageLen = std::min(64, text.length() - lastDescIndex);
    params["description"] = text.mid(lastDescIndex,messageLen);

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveDescResponse(QByteArray)));

    server->call("admin " + item.toLower() + " appendDesc", params);
    ui->status_label->setText("Saving...");
    lastDescIndex += messageLen;
}

void adminControlForm::saveDescResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            lastDescItem = parser.first("item");
            lastDescName = parser.first("name");
            QTimer::singleShot(250, this, SLOT(resaveDesc()));
        }
    }
}

void adminControlForm::resaveDesc()
{
    setEnabled(false);
    saveDescAction(lastDescName, lastDescItem);
}

void adminControlForm::getClassInfoAction(QString className)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    lastClassInfoName = className;
    QHash<QString, QString> params;
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getClassInfoResponse(QByteArray)));
    server->call("meta classes",params);
    ui->status_label->setText("Loading class...");
}

void adminControlForm::getClassInfoResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        QStringList foundNames = parser.get("classes[]");
        QString foundDesc;
        QString foundImp, foundRop, foundDap, foundVip, foundTvp, foundPrp;
        bool isFound = false;
        for (int i=0; i< foundNames.count(); ++i)
        {
            if (foundNames[i] == lastClassInfoName)
            {
                foundDesc = parser.first("descriptions["+QString::number(i)+"]");
                foundImp = parser.first("lib_imp["+QString::number(i)+"]");
                foundRop = parser.first("lib_rop["+QString::number(i)+"]");
                foundDap = parser.first("lib_dap["+QString::number(i)+"]");
                foundVip = parser.first("lib_vip["+QString::number(i)+"]");
                foundTvp = parser.first("lib_tvp["+QString::number(i)+"]");
                foundPrp = parser.first("lib_prp["+QString::number(i)+"]");
                isFound = true;
                break;
            }
        }
        ui->class_name->setText(lastClassInfoName);
        ui->class_desc->setText(foundDesc);
        ui->class_imp->setText(foundImp);
        ui->class_rop->setText(foundRop);
        ui->class_dap->setText(foundDap);
        ui->class_vip->setText(foundVip);
        ui->class_tvp->setText(foundTvp);
        ui->class_prp->setText(foundPrp);
        QTimer::singleShot(250,this, SLOT(getNextClassSpecs()));
        if (!isFound)
            QMessageBox::information(this,"Class was not found","Class was not found!");
        ui->status_label->setText(parser.first("status"));
    }
}

void adminControlForm::getNextClassSpecs()
{
    getClassSpecsAction(lastClassInfoName);
}

void adminControlForm::getClassSpecsAction(QString className)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["class_name"] = className;
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getClassSpecsResponse(QByteArray)));
    server->call("meta specs",params);
    ui->status_label->setText("Loading class specs...");
}

void adminControlForm::getClassSpecsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            QString specs = parser.first("specs");
            ui->class_specs->setText(specs);
            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText("ERROR: "+parser.first("status"));
    }
}

void adminControlForm::getFactionInfoAction(QString factionName)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    lastFactionInfoName = factionName;
    QHash<QString, QString> params;
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getFactionInfoResponse(QByteArray)));
    server->call("meta factions",params);
    ui->status_label->setText("Loading faction...");
}

void adminControlForm::getFactionInfoResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        QStringList foundNames = parser.get("factions[]");
        QString foundDesc;
        QString foundImp, foundRop, foundDap, foundVip, foundTvp, foundPrp;
        bool isFound = false;
        for (int i=0; i< foundNames.count(); ++i)
        {
            if (foundNames[i] == lastFactionInfoName)
            {
                foundDesc = parser.first("descriptions["+QString::number(i)+"]");
                foundImp = parser.first("lib_imp["+QString::number(i)+"]");
                foundRop = parser.first("lib_rop["+QString::number(i)+"]");
                foundDap = parser.first("lib_dap["+QString::number(i)+"]");
                foundVip = parser.first("lib_vip["+QString::number(i)+"]");
                foundTvp = parser.first("lib_tvp["+QString::number(i)+"]");
                foundPrp = parser.first("lib_prp["+QString::number(i)+"]");
                isFound = true;
                break;
            }
        }
        ui->faction_name->setText(lastFactionInfoName);
        ui->faction_desc->setText(foundDesc);
        ui->faction_imp->setText(foundImp);
        ui->faction_rop->setText(foundRop);
        ui->faction_dap->setText(foundDap);
        ui->faction_vip->setText(foundVip);
        ui->faction_tvp->setText(foundTvp);
        ui->faction_prp->setText(foundPrp);
        if (!isFound)
            QMessageBox::information(this,"Faction was not found","Faction was not found!");
        ui->status_label->setText(parser.first("status"));
    }
}

void adminControlForm::getFactionRelationsAction(QString factionName)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    lastFactionInfoName = factionName;
    QHash<QString, QString> params;
    params["relation_type"] = "faction";
    params["relation_name"] = lastFactionInfoName;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getFactionRelationsResponse(QByteArray)));
    server->call("meta relations",params);

    int percent = factions.indexOf(factionName) * 100 / factions.count();
    ui->status_label->setText("Loading relations... " + QString::number(percent) + "%");
}

void adminControlForm::getFactionRelationsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            QString name = parser.first("name");
            QString hostile = parser.first("hostile");
            QString friendly = parser.first("friendly");
            QStringList hostileTokens;
            QStringList friendlyTokens;
            if (!hostile.isEmpty())
                hostileTokens = hostile.split("-");
            if (!friendly.isEmpty())
                friendlyTokens = friendly.split("-");
            factionRelations[name] = compileRelations(factions,hostileTokens,friendlyTokens);

            QTimer::singleShot(500,this,SLOT(nextFactionRelation()));
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
}

QList<RelationDesc> adminControlForm::compileRelations(QStringList items, QStringList hostile, QStringList friendly)
{
    QList<RelationDesc> result;
    foreach (const QString& item, items)
    {
        RelationDesc r;
        r.factionName = item;
        if (hostile.contains(item,Qt::CaseInsensitive))
            r.relation = r.HOSTILE;
        else if (friendly.contains(item,Qt::CaseInsensitive))
            r.relation = r.FRIENDLY;
        else
            r.relation = r.NEUTRAL;
        result.append(r);
    }
    return result;
}

void adminControlForm::nextFactionRelation()
{
    int currentIndex = factions.indexOf(lastFactionInfoName);
    currentIndex++;
    if (currentIndex < factions.count())
        getFactionRelationsAction(factions.at(currentIndex));
    else
    {
        ui->status_label->setText("OK");
        renderFactionRelations();
    }
}

void adminControlForm::renderFactionRelations()
{
    while(ui->faction_relations->rowCount())
        ui->faction_relations->removeRow(0);
    while(ui->faction_relations->columnCount())
        ui->faction_relations->removeColumn(0);
    for (QHash<QString, QComboBox*>::iterator it = factionTableItems.begin(); it != factionTableItems.end(); ++it)
        delete it.value();
    factionTableItems.clear();
    ui->faction_relations->setColumnCount(factions.count());
    ui->faction_relations->setRowCount(factions.count());
    ui->faction_relations->setHorizontalHeaderLabels(factions);
    for (int c = 0; c < ui->faction_relations->horizontalHeader()->count(); ++c)
    {
        ui->faction_relations->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        ui->faction_relations->verticalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
    ui->faction_relations->setVerticalHeaderLabels(factions);

    for (int i=0; i<factions.count(); i++)
    for (int j=0; j<factions.count(); j++)
    {
        QComboBox *comboBox = new QComboBox(0);
        comboBox->addItem("friendly");
        comboBox->addItem("neutral");
        comboBox->addItem("hostile");
        if (!factionRelations.contains(factions.at(j)))
            comboBox->setCurrentIndex(1);
        else if (factionRelations[factions.at(j)].at(i).relation == RelationDesc::FRIENDLY)
            comboBox->setCurrentIndex(0);
        else if (factionRelations[factions.at(j)].at(i).relation == RelationDesc::HOSTILE)
            comboBox->setCurrentIndex(2);
        else
            comboBox->setCurrentIndex(1);

        factionTableItems["x"+QString::number(i)+"y"+QString::number(j)] = comboBox;
        ui->faction_relations->setCellWidget(j,i,comboBox);
    }
}

void adminControlForm::getClassRelationsAction(QString className)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    lastClassInfoName = className;
    QHash<QString, QString> params;
    params["relation_type"] = "class";
    params["relation_name"] = className;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getClassRelationsResponse(QByteArray)));
    server->call("meta relations",params);


    int percent = races.indexOf(className) * 100 / className.count();
    ui->status_label->setText("Loading relations... " + QString::number(percent) + "%");
}

void adminControlForm::getClassRelationsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            QString name = parser.first("name");
            QString hostile = parser.first("hostile");
            QString friendly = parser.first("friendly");
            QStringList hostileTokens;
            QStringList friendlyTokens;
            if (!hostile.isEmpty())
                hostileTokens = hostile.split("-");
            if (!friendly.isEmpty())
                friendlyTokens = friendly.split("-");
            classRelations[name] = compileRelations(races,hostileTokens,friendlyTokens);

            QTimer::singleShot(500,this,SLOT(nextClassRelation()));
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
}

void adminControlForm::nextClassRelation()
{
    int currentIndex = races.indexOf(lastClassInfoName);
    currentIndex++;
    if (currentIndex < races.count())
        getClassRelationsAction(races.at(currentIndex));
    else
    {
        ui->status_label->setText("OK");
        renderClassRelations();
    }
}

void adminControlForm::renderClassRelations()
{
    while(ui->class_relations->rowCount())
        ui->class_relations->removeRow(0);
    while(ui->class_relations->columnCount())
        ui->class_relations->removeColumn(0);
    for (QHash<QString, QComboBox*>::iterator it = classTableItems.begin(); it != classTableItems.end(); ++it)
        delete it.value();
    classTableItems.clear();
    ui->class_relations->setColumnCount(races.count());
    ui->class_relations->setRowCount(races.count());
    ui->class_relations->setHorizontalHeaderLabels(races);
    for (int c = 0; c < ui->class_relations->horizontalHeader()->count(); ++c)
    {
        ui->class_relations->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        ui->class_relations->verticalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
    ui->class_relations->setVerticalHeaderLabels(races);

    for (int i=0; i<races.count(); i++)
    for (int j=0; j<races.count(); j++)
    {
        QComboBox *comboBox = new QComboBox(0);
        comboBox->addItem("friendly");
        comboBox->addItem("neutral");
        comboBox->addItem("hostile");
        if (!classRelations.contains(races.at(j)))
            comboBox->setCurrentIndex(1);
        else if (classRelations[races.at(j)].at(i).relation == RelationDesc::FRIENDLY)
            comboBox->setCurrentIndex(0);
        else if (classRelations[races.at(j)].at(i).relation == RelationDesc::HOSTILE)
            comboBox->setCurrentIndex(2);
        else
            comboBox->setCurrentIndex(1);

        classTableItems["x"+QString::number(i)+"y"+QString::number(j)] = comboBox;
        ui->class_relations->setCellWidget(j,i,comboBox);
    }
}

void adminControlForm::saveFactionRelationsAction(QString factionName)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    lastFactionInfoName = factionName;
    QHash<QString, QString> params;
    params["rel_type"] = "faction";
    params["rel_name"] = lastFactionInfoName;
    params["apikey"] = currentUser.apikey;

    QString hostileStr = "";
    QString friendlyStr = "";
    for (int i=0; i<factions.count(); i++)
    {
        QString item = factionTableItems["x"+QString::number(i)+"y"+QString::number(factions.indexOf(factionName))]->currentText();
        if (item == "hostile")
        {
            hostileStr += factions.at(i);
            if (i != factions.count()-1)
                hostileStr += "-";
        }
        else if (item == "friendly")
        {
            friendlyStr += factions.at(i);
            if (i != factions.count()-1)
                friendlyStr += "-";
        }
    }
    params["h"] = hostileStr;
    params["f"] = friendlyStr;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveFactionRelationsResponse(QByteArray)));
    server->call("admin createRelation",params);


    int percent = factions.indexOf(factionName) * 100 / factions.count();
    ui->status_label->setText("Saving relations... " + QString::number(percent) + "%");
}

void adminControlForm::saveFactionRelationsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            QTimer::singleShot(250,this,SLOT(nextFactionSave()));
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
}

void adminControlForm::nextFactionSave()
{
    int currentIndex = factions.indexOf(lastFactionInfoName);
    currentIndex++;
    if (currentIndex < factions.count())
        saveFactionRelationsAction(factions.at(currentIndex));
    else
    {
        ui->status_label->setText("OK");
    }
}

void adminControlForm::saveClassRelationsAction(QString className)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    lastClassInfoName = className;
    QHash<QString, QString> params;
    params["rel_type"] = "class";
    params["rel_name"] = className;
    params["apikey"] = currentUser.apikey;

    QString hostileStr = "";
    QString friendlyStr = "";
    for (int i=0; i<races.count(); i++)
    {
        QString item = classTableItems["x"+QString::number(i)+"y"+QString::number(races.indexOf(className))]->currentText();
        if (item == "hostile")
        {
            hostileStr += races.at(i);
            if (i != races.count()-1)
                hostileStr += "-";
        }
        else if (item == "friendly")
        {
            friendlyStr += races.at(i);
            if (i != races.count()-1)
                friendlyStr += "-";
        }
    }
    params["h"] = hostileStr;
    params["f"] = friendlyStr;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveClassRelationsResponse(QByteArray)));
    server->call("admin createRelation",params);


    int percent = races.indexOf(className) * 100 / className.count();
    ui->status_label->setText("Saving relations... " + QString::number(percent) + "%");
}

void adminControlForm::saveClassRelationsResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            QTimer::singleShot(250,this,SLOT(nextClassSave()));
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
}

void adminControlForm::nextClassSave()
{
    int currentIndex = races.indexOf(lastClassInfoName);
    currentIndex++;
    if (currentIndex < races.count())
        saveClassRelationsAction(races.at(currentIndex));
    else
    {
        ui->status_label->setText("OK");
    }
}

void adminControlForm::loadSpellsForClassAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["spell_class"] = ui->spell_class_combobox->currentText();

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(loadSpellsForClassResponse(QByteArray)));
    server->call("admin spells",params);

    setEnabled(false);
    ui->status_label->setText("Loading spells List... ");
}

void adminControlForm::loadSpellsForClassResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->spells_combobox->clear();
            int spells_count = parser.getInt("spells_count");
            for (int i=0; i<spells_count; i++)
            {
                QString it = QString::number(i);
                QString spell_name = parser.first("spells["+it+"].spell_name");
                QString spell_desc = parser.first("spells["+it+"].spell_desc");

                spells[spell_name] = spell_desc;
                spell_descriptors[spell_name] = SpellDescriptor::fromString(spell_desc);
                ui->spells_combobox->addItem(parser.first("spells["+it+".spell_name"));

            }
            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::saveSpellForClassAction()
{
    SpellDescriptor spell;
    spell.cd = ui->spell_cd->text();
    spell.cost = ui->spell_cost->text();
    spell.level_scales = ui->spell_level_scale->text();
    spell.req = ui->spells_req->text();
    spell.spell_name = ui->spells_spell_name->text();
    spell.stat_scales = ui->spell_stats_scale->text();
    QStringList effectList;
    for (int i=0; i< ui->spell_effect_list->count(); i++)
        effectList.append(ui->spell_effect_list->item(i)->text());
    spell.effects = effectList;
    QString spellDesc = spell.toString();
    QClipboard *clb = QApplication::clipboard();
    clb->setText(spellDesc);
    QMessageBox::information(this,"",spellDesc,QMessageBox::Ok);
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["sc"] = ui->spell_class_combobox->currentText();
    if (ui->spells_combobox->currentText() != spell.spell_name)
        params["rn"] = spell.spell_name;
    params["sn"] = ui->spells_combobox->currentText();
    params["d"] = spellDesc;
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveSpellForClassResponse(QByteArray)));
    server->call("admin spells save",params);

    setEnabled(false);
    ui->status_label->setText("Saving spell... ");
}

void adminControlForm::saveSpellForClassResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->status_label->setText("OK");
            QTimer::singleShot(150,this,SLOT(loadSpellsForClassAction()));
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::destroySpellAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["spell_class"] = ui->spell_class_combobox->currentText();
    params["spell_name"] = ui->spells_combobox->currentText();

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(destroySpellResponse(QByteArray)));
    server->call("admin spells destroy",params);

    setEnabled(false);
    ui->status_label->setText("Destroying spell... ");
}

void adminControlForm::destroySpellResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->status_label->setText("OK");
            QTimer::singleShot(150,this,SLOT(loadSpellsForClassAction()));
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::getCreaturesInfoAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getCreaturesInfoResponse(QByteArray)));
    server->call("admin creatures",params);

    setEnabled(false);
    ui->status_label->setText("Loading creatures info...");
}

void adminControlForm::getCreaturesInfoResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            mods.clear();
            ui->creature_mod->clear();
            int modsCount = parser.getInt("mods_count");
            for (int i=0; i<modsCount; i++)
            {
                QString maleMod = parser.first("mods_male[" + QString::number(i) + "].value");
                QString femaleMod = parser.first("mods_female[" + QString::number(i) + "].value");
                QString naMod = parser.first("mods_na[" + QString::number(i) + "].value");
                mods["male"][maleMod] = parser.first("mods_male[" + QString::number(i) + "].item");
                mods["female"][femaleMod] = parser.first("mods_female[" + QString::number(i) + "].item");
                mods["na"][naMod] = parser.first("mods_na[" + QString::number(i) + "].item");

                if (ui->creature_gender_male->isChecked())
                    ui->creature_mod->addItem(maleMod);
                else if (ui->creature_gender_female->isChecked())
                    ui->creature_mod->addItem(femaleMod);
                else
                    ui->creature_mod->addItem(naMod);
            }
            setCurrentGender("male");

            allSpells.clear();
            ui->creature_spell_combobox->clear();
            int allSpellsCount = parser.getInt("all_spells_count");
            for (int i=0; i< allSpellsCount; i++)
            {
                SpellDescriptor s;
                QString spellName, spellClass;
                spellName = parser.first("all_spells[" + QString::number(i) + "].spell_name");
                spellClass = parser.first("all_spells[" + QString::number(i) + "].spell_class");
                s.spell_name = spellName;
                s.spell_class = spellClass;
                allSpells[spellClass + ":" + spellName] = s;
                ui->creature_spell_combobox->addItem(spellClass + ":" + spellName);
            }

            creatures.clear();
            creatureSpells.clear();
            ui->creatures_combobox->clear();
            int creaturesCount = parser.getInt("creature_count");
            for (int i=0; i<creaturesCount; i++)
            {
                CreatureDescriptor c;
                QString creatureName = parser.first("creatures[" + QString::number(i) + "].creature_name");
                if (creatureName == "")
                    continue;
                c.creatureName = creatureName;
                c.creatureType = "creature";
                c.dex = parser.getInt("creatures[" + QString::number(i) + "].dex");
                c.str = parser.getInt("creatures[" + QString::number(i) + "].str");
                c.mag = parser.getInt("creatures[" + QString::number(i) + "].mag");
                c.intel = parser.getInt("creatures[" + QString::number(i) + "].int");
                c.tra = parser.getInt("creatures[" + QString::number(i) + "].tra");
                c.vel = parser.getInt("creatures[" + QString::number(i) + "].vel");
                c.hp = parser.getInt("creatures[" + QString::number(i) + "].hp");
                c.mana = parser.getInt("creatures[" + QString::number(i) + "].mana");
                c.gender = parser.first("creatures[" + QString::number(i) + "].gender");
                c.mod = parser.first("creatures[" + QString::number(i) + "].mod");
                creatures[creatureName + ":" + c.mod] = c;
                if (ui->creatures_combobox->findText(creatureName) == -1)
                    ui->creatures_combobox->addItem(creatureName);

                QList<SpellDescriptor> currentCreatureSpells;
                int creatureSpellCount = parser.getInt("creature_spells."+creatureName+".spell_count");
                for (int j=0; j<creatureSpellCount; j++)
                {
                    SpellDescriptor spell;
                    spell.spell_class = parser.first("creature_spells."+creatureName+".spells["+QString::number(j)+"].spell_class");
                    spell.spell_name = parser.first("creature_spells."+creatureName+".spells["+QString::number(j)+"].spell_name");
                    spell.mod = parser.first("creature_spells."+creatureName + ".spells["+QString::number(j) + "].mod");
                    currentCreatureSpells.append(spell);
                }
                if (!currentCreatureSpells.isEmpty())
                    creatureSpells[creatureName] = currentCreatureSpells;
            }

            setCurrentGender(creatures[ui->creatures_combobox->itemText(0)+":"+ui->creature_mod->currentText()].gender);
            renderCreature("creature", getCurrentMod(), ui->creatures_combobox->itemText(0));

            prefixes.clear();
            prefixSpells.clear();
            int prefixesCount = parser.getInt("prefix_count");
            for (int i=0; i<prefixesCount; i++)
            {
                CreatureDescriptor c;
                QString creatureName = parser.first("prefixes[" + QString::number(i) + "].creature_name");
                c.creatureName = creatureName;
                c.creatureType = "prefix";
                c.dex = parser.getInt("prefixes[" + QString::number(i) + "].dex");
                c.str = parser.getInt("prefixes[" + QString::number(i) + "].str");
                c.mag = parser.getInt("prefixes[" + QString::number(i) + "].mag");
                c.intel = parser.getInt("prefixes[" + QString::number(i) + "].int");
                c.tra = parser.getInt("prefixes[" + QString::number(i) + "].tra");
                c.vel = parser.getInt("prefixes[" + QString::number(i) + "].vel");
                c.hp = parser.getInt("prefixes[" + QString::number(i) + "].hp");
                c.mana = parser.getInt("prefixes[" + QString::number(i) + "].mana");
                c.gender = parser.first("prefixes[" + QString::number(i) + "].gender");
                c.mod = parser.first("prefixes[" + QString::number(i) + "].mod");
                prefixes[creatureName] = c;


                QList<SpellDescriptor> currentPrefixSpells;
                int prefixSpellCount = parser.getInt("prefix_spells."+creatureName+".spell_count");
                for (int j=0; j<prefixSpellCount; j++)
                {
                    SpellDescriptor spell;
                    spell.spell_class = parser.first("prefix_spells."+creatureName+".spells["+QString::number(j)+"].spell_class");
                    spell.spell_name = parser.first("prefix_spells."+creatureName+".spells["+QString::number(j)+"].spell_name");
                    spell.mod = parser.first("prefix_spells."+creatureName + ".spells["+QString::number(j) + "].mod");
                    currentPrefixSpells.append(spell);
                }
                if (!currentPrefixSpells.isEmpty())
                    prefixSpells[creatureName] = currentPrefixSpells;
            }

            suffixes.clear();
            suffixSpells.clear();
            int suffixCount = parser.getInt("suffix_count");
            for (int i=0; i<suffixCount; i++)
            {
                CreatureDescriptor c;
                QString creatureName = parser.first("suffixes[" + QString::number(i) + "].creature_name");
                c.creatureName = creatureName;
                c.creatureType = "creature";
                c.dex = parser.getInt("suffixes[" + QString::number(i) + "].dex");
                c.str = parser.getInt("suffixes[" + QString::number(i) + "].str");
                c.mag = parser.getInt("suffixes[" + QString::number(i) + "].mag");
                c.intel = parser.getInt("suffixes[" + QString::number(i) + "].int");
                c.tra = parser.getInt("suffixes[" + QString::number(i) + "].tra");
                c.vel = parser.getInt("suffixes[" + QString::number(i) + "].vel");
                c.hp = parser.getInt("suffixes[" + QString::number(i) + "].hp");
                c.mana = parser.getInt("suffixes[" + QString::number(i) + "].mana");
                c.gender = parser.first("suffixes[" + QString::number(i) + "].gender");
                c.mod = parser.first("suffixes[" + QString::number(i) + "].mod");
                suffixes[creatureName] = c;

                QList<SpellDescriptor> currentSuffixSpells;
                int suffixSpellCount = parser.getInt("suffix_spells."+creatureName+".spell_count");
                for (int j=0; j<suffixSpellCount; j++)
                {
                    SpellDescriptor spell;
                    spell.spell_class = parser.first("suffix_spells."+creatureName+".spells["+QString::number(j)+"].spell_class");
                    spell.spell_name = parser.first("suffix_spells."+creatureName+".spells["+QString::number(j)+"].spell_name");
                    spell.mod = parser.first("suffix_spells."+creatureName + ".spells["+QString::number(j) + "].mod");
                    currentSuffixSpells.append(spell);
                }
                if (!currentSuffixSpells.isEmpty())
                    suffixSpells[creatureName] = currentSuffixSpells;
            }

            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::saveCreatureAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["creature_type"] = ui->creature_type_combobox->currentText();
    params["creature_name"] = ui->creatures_combobox->currentText();
    if (ui->creatures_combobox->currentText() != ui->creature_name->text())
        params["rename"] = ui->creature_name->text();
    params["mod"] = getCurrentMod();
    params["gender"] = ui->creature_gender_male->isChecked() ? "male" : (ui->creature_gender_female->isChecked() ? "female" : "na");
    params["str"] = QString::number(ui->creature_stats_str->value());
    params["dex"] = QString::number(ui->creature_stats_dex->value());
    params["mag"] = QString::number(ui->creature_stats_mag->value());
    params["int"] = QString::number(ui->creature_stats_int->value());
    params["tra"] = QString::number(ui->creature_stats_tra->value());
    params["vel"] = QString::number(ui->creature_stats_vel->value());
    params["hp"] = QString::number(ui->creature_stats_hp->value());
    params["mana"] = QString::number(ui->creature_stats_mana->value());

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveCreatureResponse(QByteArray)));
    server->call("admin creatures save",params);

    setEnabled(false);
    ui->status_label->setText("Saving Creature...");
}

void adminControlForm::saveCreatureResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::saveCreatureSpellAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }

    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["spell"] = ui->creature_spell_combobox->currentText().replace(":","@");
    params["creature_type"] = ui->creature_type_combobox->currentText();
    params["creature_name"] = ui->creatures_combobox->currentText();
    params["mod"] = getCurrentMod();


    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveCreatureSpellResponse(QByteArray)));
    server->call("admin.creatures.spells add",params);

    setEnabled(false);
    ui->status_label->setText("Saving Spell...");
}

void adminControlForm::saveCreatureSpellResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::removeCreatureSpellAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }

    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    if (updateSpell != "")
    {
        params["spell"] = updateSpell.replace(":","@");
        updateSpell = "";
    }
    else
        params["spell"] = ui->creature_spell_list->currentItem()->text().replace(":","@");
    params["creature_type"] = ui->creature_type_combobox->currentText();
    params["creature_name"] = ui->creatures_combobox->currentText();
    params["mod"] = getCurrentMod();


    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(removeCreatureSpellResponse(QByteArray)));
    server->call("admin.creatures.spells destroy",params);

    setEnabled(false);
    ui->status_label->setText("Removing Spell...");
}

void adminControlForm::removeCreatureSpellResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            ui->status_label->setText("OK");
        }
        else
            ui->status_label->setText(parser.first("status"));
    }
    setEnabled(true);
}

void adminControlForm::updateCreatureSpellAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }

    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["spell"] = ui->creature_spell_combobox->currentText().replace(":","@");
    params["creature_type"] = ui->creature_type_combobox->currentText();
    params["creature_name"] = ui->creatures_combobox->currentText();
    params["mod"] = getCurrentMod();


    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(updateCreatureSpellResponse(QByteArray)));
    server->call("admin.creatures.spells add",params);

    setEnabled(false);
    ui->status_label->setText("Saving Spell...");
}

void adminControlForm::updateCreatureSpellResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
    {
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
        setEnabled(true);
    }
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            updateSpell = ui->creature_spell_list->currentItem()->text();
            ui->creature_spell_list->currentItem()->setText(ui->creature_spell_combobox->currentText());

            SpellDescriptor sd;
            QStringList spellDescTokens = ui->creature_spell_combobox->currentText().split(":");
            sd.spell_class = spellDescTokens.at(0);
            sd.spell_name = spellDescTokens.at(1);
            if (ui->creature_type_combobox->currentText() == "creature")
                creatureSpells[ui->creatures_combobox->currentText()].append(sd);
            else if (ui->creature_type_combobox->currentText() == "prefix")
                prefixSpells[ui->creatures_combobox->currentText()].append(sd);
            else if (ui->creature_type_combobox->currentText() == "suffix")
                suffixSpells[ui->creatures_combobox->currentText()].append(sd);

            QTimer::singleShot(150,this, SLOT(removeCreatureSpellAction()));
            ui->status_label->setText("OK");
        }
        else
        {
            ui->status_label->setText(parser.first("status"));
            setEnabled(true);
        }
    }
}





void adminControlForm::on_pushButton_clicked()
{
    searchHeroesForLoginAction(ui->lineEdit->text(), currentUser.apikey);
}

void adminControlForm::on_found_heroes_currentIndexChanged(int)
{
    for (int i=0; i< ui->faction_combobox->count(); i++)
        if (ui->faction_combobox->itemText(i).toLower() == foundHeroes[ui->found_heroes->currentText()].faction)
            ui->faction_combobox->setCurrentIndex(i);
    for (int i=0; i< ui->class_combobox->count(); i++)
        if (ui->class_combobox->itemText(i).toLower() == foundHeroes[ui->found_heroes->currentText()].race)
            ui->class_combobox->setCurrentIndex(i);
    ui->level_label->setText(QString::number(foundHeroes[ui->found_heroes->currentText()].lvl));
}

void adminControlForm::on_pushButton_4_clicked()
{
    newFactionAction(ui->faction_name->text(), currentUser.apikey,
                     ui->faction_imp->text(), ui->faction_rop->text(), ui->faction_dap->text(),
                     ui->faction_vip->text(), ui->faction_tvp->text(), ui->faction_prp->text());
}

void adminControlForm::on_pushButton_5_clicked()
{
    newClassAction(ui->class_name->text(),
                   currentUser.apikey,
                   ui->class_imp->text(), ui->class_rop->text(), ui->class_dap->text(),
                   ui->class_vip->text(), ui->class_tvp->text(), ui->class_prp->text());
}

void adminControlForm::on_pushButton_2_clicked()
{
    bool ok;
    QString text = QInputDialog::getItem(this,"Load class","class: ", races,0,false,&ok);
    if (ok)
        getClassInfoAction(text);
}

void adminControlForm::on_pushButton_10_clicked()
{
    bool ok;
    QString text = QInputDialog::getItem(this,"Load Faction","faction: ", factions,0,false,&ok);
    if (ok)
        getFactionInfoAction(text);
}

void adminControlForm::on_faction_reload_clicked()
{
    searchFactionsAction();
}

void adminControlForm::on_class_reload_clicked()
{
    searchRacesAction();
}


RelationDesc::Relation RelationDesc::getRelationByString(QString desc)
{
    if (desc.toLower() == "hostile")
        return HOSTILE;
    if (desc.toLower() == "neutral")
        return NEUTRAL;
    if (desc.toLower() == "friendly")
        return FRIENDLY;
    return NEUTRAL;
}

void adminControlForm::on_pushButton_7_clicked()
{
    if (factions.isEmpty())
    {
        QMessageBox::warning(this,"No factions to load!","Factions are not loaded yet or do not exist");
        return;
    }
    lastFactionInfoName = factions.at(0);
    getFactionRelationsAction(lastFactionInfoName);
}

void adminControlForm::on_pushButton_6_clicked()
{

    if (factions.isEmpty())
    {
        QMessageBox::warning(this,"No factions to load!","Factions are not loaded yet or do not exist");
        return;
    }
    lastFactionInfoName = factions.at(0);
    saveFactionRelationsAction(lastFactionInfoName);
}

void adminControlForm::on_pushButton_9_clicked()
{
    if (races.isEmpty())
    {
        QMessageBox::warning(this,"No classes to load!","Classes are not loaded yet or do not exist");
        return;
    }
    lastClassInfoName = races.at(0);
    getClassRelationsAction(lastClassInfoName);
}

void adminControlForm::on_pushButton_8_clicked()
{
    if (races.isEmpty())
    {
        QMessageBox::warning(this,"No classes to load!","Classes are not loaded yet or do not exist");
        return;
    }
    lastClassInfoName = races.at(0);
    saveClassRelationsAction(lastClassInfoName);
}

void adminControlForm::on_pushButton_12_clicked()
{
    searchRacesAction();
}

void adminControlForm::on_pushButton_11_clicked()
{
    searchRacesAction();
}

void adminControlForm::on_pushButton_13_clicked()
{
    classSpecsDesc d = classSpecsDesc::fromString(ui->class_specs->text());
    classSpecsDialog dlg(d.str,d.dex,d.mag,d.intellect,d.tra,d.vel,d.hp,d.mana);
    if (dlg.exec())
        ui->class_specs->setText(dlg.data);
    else
        QMessageBox::information(this,"Specs rejected", "specs Rejected");
}

void adminControlForm::on_tabWidget_currentChanged(int index)
{
    //clicked on "SPELLS tab"
    if (index == 5)
    {
        ui->spell_class_combobox->clear();
        ui->spell_class_combobox->addItem("GLOBAL");
        foreach (const QString& str, races)
           ui->spell_class_combobox->addItem(str);
        ui->spell_effect_combobox->clear();
        ui->spell_effect_combobox->addItem("stun");
        ui->spell_effect_combobox->addItem("dmg.hp");
        ui->spell_effect_combobox->addItem("dmg.mana");
        ui->spell_effect_combobox->addItem("dmg.both");
        ui->spell_effect_combobox->addItem("heal.hp");
        ui->spell_effect_combobox->addItem("heal.mana");
        ui->spell_effect_combobox->addItem("heal.both");
        ui->spell_effect_combobox->addItem("poison");
        ui->spell_effect_combobox->addItem("shield.attack.1");
        ui->spell_effect_combobox->addItem("shield.attack.2");
        ui->spell_effect_combobox->addItem("shield.attack.3");
        ui->spell_effect_combobox->addItem("shield.attack.99");
        ui->spell_effect_combobox->addItem("shield.spell.1");
        ui->spell_effect_combobox->addItem("shield.spell.2");
        ui->spell_effect_combobox->addItem("shield.spell.3");
        ui->spell_effect_combobox->addItem("shield.spell.99");
        ui->spell_effect_combobox->addItem("shield.both.1");
        ui->spell_effect_combobox->addItem("shield.both.2");
        ui->spell_effect_combobox->addItem("shield.both.3");
        ui->spell_effect_combobox->addItem("shield.both.99");
        ui->spell_effect_combobox->addItem("buff.str");
        ui->spell_effect_combobox->addItem("buff.dex");
        ui->spell_effect_combobox->addItem("buff.mag");
        ui->spell_effect_combobox->addItem("buff.int");
        ui->spell_effect_combobox->addItem("buff.tra");
        ui->spell_effect_combobox->addItem("buff.vel");
        ui->spell_effect_combobox->addItem("buff.hp");
        ui->spell_effect_combobox->addItem("buff.mana");
        ui->spell_effect_combobox->addItem("debuff.str");
        ui->spell_effect_combobox->addItem("debuff.dex");
        ui->spell_effect_combobox->addItem("debuff.mag");
        ui->spell_effect_combobox->addItem("debuff.int");
        ui->spell_effect_combobox->addItem("debuff.tra");
        ui->spell_effect_combobox->addItem("debuff.vel");
        ui->spell_effect_combobox->addItem("debuff.hp");
        ui->spell_effect_combobox->addItem("debuff.mana");
        ui->spell_effect_combobox->addItem("disarm");
        ui->spell_effect_combobox->addItem("cleanse");

        ui->spell_effect_mod_combobox->clear();
        ui->spell_effect_mod_combobox->addItem("");
        ui->spell_effect_mod_combobox->addItem("aoe.ally");
        ui->spell_effect_mod_combobox->addItem("aoe.enemy");
        ui->spell_effect_mod_combobox->addItem("aoe.enemy.ho");
        ui->spell_effect_mod_combobox->addItem("aoe.enemy.mo");
        ui->spell_effect_mod_combobox->addItem("aoe.both");
        ui->spell_effect_mod_combobox->addItem("aoe.both.ho");
        ui->spell_effect_mod_combobox->addItem("aoe.both.mo");

        loadSpellsForClassAction();
    }
    else if (index == 6)
    {
        getCreaturesInfoAction();
    }
}


SpellDescriptor SpellDescriptor::fromString(QString str)
{
    str = str.replace("@", ",").replace("_", ";");
    SpellDescriptor result;
    //n:simple nuke with stun;r:i=10,m=8;e:dmg.hp=7,stun=1,dmg.mana:3;l:2,0.25,1,-0.25,5;s:0,0,0.1*STR|0.2*MAG;cd:3;c:15
    QStringList tokens = str.split(";");
    foreach (const QString& typeToken, tokens)
    {
        QStringList commandTokens = typeToken.split(":");
        if (commandTokens.first() == "n")
            result.spell_name = commandTokens.at(1);
        else if (commandTokens.first() == "r")
            result.req = commandTokens.at(1);
        else if (commandTokens.first() == "l")
            result.level_scales = commandTokens.at(1);
        else if (commandTokens.first() == "s")
            result.stat_scales = commandTokens.at(1);
        else if (commandTokens.first() == "cd")
            result.cd = commandTokens.at(1);
        else if (commandTokens.first() == "c")
            result.cost = commandTokens.at(1);
        else if (commandTokens.first() == "e")
        {
            QStringList effectTokens = commandTokens.at(1).split(",");
            foreach (const QString& effectToken, effectTokens)
                result.effects.append(effectToken);
        }
    }
    return result;
}

bool SpellDescriptor::operator==(const SpellDescriptor &r)
{
    return (r.cd == cd) && (r.cost == cost) && (r.effects == effects) && (r.level_scales == level_scales) &&
           (r.req == req) && (r.spell_class == spell_class) && (r.spell_name == spell_name) && (r.stat_scales == stat_scales);
}

QString SpellDescriptor::toString()
{
    QString result = "n:"+spell_name+";r:"+req+";l:"+level_scales+";s:"+stat_scales+";cd:"+cd+";c:"+cost+";e:";
    for(int i=0; i< effects.count(); ++i)
    {
        result += effects.at(i);
        if (i != effects.count()-1)
            result+=",";
    }
    result = result.replace(";","_").replace(",","@");
    return result;
}

void adminControlForm::on_spells_combobox_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "" || !spell_descriptors.contains(arg1))
        return;
    ui->spells_spell_name->setText(arg1);
    ui->spells_req->setText(spell_descriptors[arg1].req);
    ui->spell_cd->setValue(spell_descriptors[arg1].cd.toInt());
    ui->spell_cost->setValue(spell_descriptors[arg1].cost.toInt());
    ui->spell_level_scale->setText(spell_descriptors[arg1].level_scales);
    ui->spell_stats_scale->setText(spell_descriptors[arg1].stat_scales);
    ui->spell_effect_list->clear();
    ui->spell_effect_list->addItems(spell_descriptors[arg1].effects);
}

void adminControlForm::on_spell_effect_list_currentRowChanged(int currentRow)
{
    if (ui->spell_effect_list->count() == 0 || ui->spell_effect_list->item(currentRow) == 0)
    {
        ui->spell_effect_combobox->setCurrentIndex(0);
        ui->spell_effect_mod_combobox->setCurrentIndex(0);
        ui->spell_value->setText("0");
        return;
    }
    QStringList effectTokens = ui->spell_effect_list->item(currentRow)->text().split("=");
    QStringList effectModTokens = effectTokens.at(1).split(".");
    QString mod = "";
    QString value = "";
    if (effectModTokens.count() != 1)
    {
        for (int i=0; i< effectModTokens.count()-1; i++)
        {
            mod += effectModTokens.at(i);
            if (i != effectModTokens.count() - 2)
                mod += ".";
            else
            {
                value = effectModTokens.at(i+1);
            }
        }
    }
    else
        value = effectTokens.at(1);
    ui->spell_effect_mod_combobox->setCurrentIndex(ui->spell_effect_mod_combobox->findText(mod));
    ui->spell_effect_combobox->setCurrentIndex(ui->spell_effect_combobox->findText(effectTokens.first()));
    ui->spell_value->setText(value);
}

void adminControlForm::on_new_effect_clicked()
{
    if (ui->spell_value->text() != "")
    {
        ui->spell_effect_list->addItem(ui->spell_effect_combobox->currentText() + "=" + ui->spell_effect_mod_combobox->currentText()
                                       + (ui->spell_effect_mod_combobox->currentText() == "" ? "" : ".") + ui->spell_value->text());
        ui->spell_value->setText("");
    }
}

void adminControlForm::on_update_effect_clicked()
{
    if (ui->spell_value->text() != "")
    {
        ui->spell_effect_list->currentItem()->setText(ui->spell_effect_combobox->currentText() + "=" + ui->spell_effect_mod_combobox->currentText()
                                                      + (ui->spell_effect_mod_combobox->currentText() == "" ? "" : ".") + ui->spell_value->text());
    }
}

void adminControlForm::on_pushButton_14_clicked()
{
    SpellRequirementsDialog dlg;
    if (dlg.exec())
    {
        ui->spells_req->setText(dlg.getReq());
    }
}

void adminControlForm::on_pushButton_19_clicked()
{
    saveSpellForClassAction();
}

void adminControlForm::on_spell_class_combobox_currentIndexChanged(const QString &)
{
    loadSpellsForClassAction();
}

void adminControlForm::on_pushButton_18_clicked()
{
    delete ui->spell_effect_list->takeItem(ui->spell_effect_list->currentRow());
}

void adminControlForm::on_pushButton_15_clicked()
{
    QStringList effects;
    for (int i=0; i<ui->spell_effect_list->count(); i++)
        effects.append(ui->spell_effect_list->item(i)->text());
    SpellScalesDialog dlg(effects,true,this);
    if (dlg.exec())
        ui->spell_level_scale->setText(dlg.getScale());
}

void adminControlForm::on_pushButton_16_clicked()
{
    QStringList effects;
    for (int i=0; i<ui->spell_effect_list->count(); i++)
        effects.append(ui->spell_effect_list->item(i)->text());
    SpellScalesDialog dlg(effects,false,this);
    if (dlg.exec())
        ui->spell_stats_scale->setText(dlg.getScale());
}

void adminControlForm::on_pushButton_17_clicked()
{
    destroySpellAction();
}



void adminControlForm::on_creature_save_clicked()
{
    saveCreatureAction();
}

QString adminControlForm::getCurrentMod()
{
    if (ui->creature_type_combobox->currentText() != "creature")
        return ui->creature_mod->currentText();
    if (ui->creature_gender_male->isChecked() && mods["male"].contains(ui->creature_mod->currentText()))
        return mods["male"][ui->creature_mod->currentText()];
    if (ui->creature_gender_female->isChecked() && mods["female"].contains(ui->creature_mod->currentText()))
        return mods["female"][ui->creature_mod->currentText()];
    else
        return mods["na"][ui->creature_mod->currentText()];
}

void adminControlForm::renderCreature(QString creatureType, QString creatureMod, QString creatureName)
{
    if (creatureType == "creature")
    {
        if (!creatures.contains(creatureName + ":" + creatureMod))
        {
            clearCreatureInfo();
            return;
        }

        CreatureDescriptor c = creatures[creatureName + ":" + creatureMod];

        ui->creature_name->setText(creatureName);
        ui->creature_stats_str->setValue(c.str);
        ui->creature_stats_dex->setValue(c.mag);
        ui->creature_stats_mag->setValue(c.mag);
        ui->creature_stats_int->setValue(c.intel);
        ui->creature_stats_tra->setValue(c.tra);
        ui->creature_stats_vel->setValue(c.vel);
        ui->creature_stats_hp->setValue(c.hp);
        ui->creature_stats_mana->setValue(c.mana);

        ui->creature_spell_list->clear();
        if (creatureSpells.contains(creatureName))
        {
            QList<SpellDescriptor> spellsForCreature = creatureSpells[creatureName];
            foreach (const SpellDescriptor& spell, spellsForCreature)
                if (spell.mod == getCurrentMod())
                    ui->creature_spell_list->addItem(spell.spell_class + ":" + spell.spell_name);
        }
    }
    else if (creatureType == "prefix")
    {
        CreatureDescriptor c;
        bool found = false;
        for(QHash<QString, CreatureDescriptor>::iterator it = prefixes.begin(); it != prefixes.end(); ++it)
            if (it.value().creatureName == creatureName && it.value().mod == creatureMod)
            {
                found = true;
                c = it.value();
                break;
            }
        if (found)
        {
            ui->creature_name->setText(creatureName);
            ui->creature_stats_str->setValue(c.str);
            ui->creature_stats_dex->setValue(c.mag);
            ui->creature_stats_mag->setValue(c.mag);
            ui->creature_stats_int->setValue(c.intel);
            ui->creature_stats_tra->setValue(c.tra);
            ui->creature_stats_vel->setValue(c.vel);
            ui->creature_stats_hp->setValue(c.hp);
            ui->creature_stats_mana->setValue(c.mana);

            ui->creature_spell_list->clear();
            if (creatureSpells.contains(creatureName))
            {
                QList<SpellDescriptor> spellsForCreature = prefixSpells[creatureName];
                foreach (const SpellDescriptor& spell, spellsForCreature)
                    if (spell.mod == getCurrentMod())
                        ui->creature_spell_list->addItem(spell.spell_class + ":" + spell.spell_name);
            }
        }
        else
            clearCreatureInfo();
    }
    else
    {
        CreatureDescriptor c;
        bool found = false;
        for(QHash<QString, CreatureDescriptor>::iterator it = suffixes.begin(); it != suffixes.end(); ++it)
            if (it.value().creatureName == creatureName && it.value().mod == creatureMod)
            {
                found = true;
                c = it.value();
                break;
            }
        if (found)
        {
            ui->creature_name->setText(creatureName);
            ui->creature_stats_str->setValue(c.str);
            ui->creature_stats_dex->setValue(c.mag);
            ui->creature_stats_mag->setValue(c.mag);
            ui->creature_stats_int->setValue(c.intel);
            ui->creature_stats_tra->setValue(c.tra);
            ui->creature_stats_vel->setValue(c.vel);
            ui->creature_stats_hp->setValue(c.hp);
            ui->creature_stats_mana->setValue(c.mana);

            ui->creature_spell_list->clear();
            if (creatureSpells.contains(creatureName))
            {
                QList<SpellDescriptor> spellsForCreature = suffixSpells[creatureName];
                foreach (const SpellDescriptor& spell, spellsForCreature)
                    if (spell.mod == getCurrentMod())
                        ui->creature_spell_list->addItem(spell.spell_class + ":" + spell.spell_name);
            }
        }
        else
            clearCreatureInfo();
    }
}

void adminControlForm::setCurrentGender(QString gender)
{
    if (gender =="")
        return;
    if (gender == "male")
        ui->creature_gender_male->setChecked(true);
    else if (gender == "female")
        ui->creature_gender_female->setChecked(true);
    else
        ui->creature_gender_na->setChecked(true);
    int prevIndex = ui->creature_mod->currentIndex();

    ui->creature_mod->disconnect();
    ui->creature_mod->clear();

    for (QMap<QString, QString>::iterator it = mods[gender].begin(); it != mods[gender].end(); ++it)
        ui->creature_mod->addItem(it.key());
    if (prevIndex == -1)
        prevIndex = 0;
    ui->creature_mod->setCurrentIndex(prevIndex);
    QObject::connect(ui->creature_mod, SIGNAL(currentIndexChanged(QString)), this, SLOT(on_creature_mod_currentIndexChanged(QString)));
}

QString adminControlForm::getCurrentGender()
{
    if (ui->creature_gender_male->isChecked())
        return "male";
    if (ui->creature_gender_female->isChecked())
        return "female";
    return "na";
}

void adminControlForm::clearCreatureInfo()
{
    ui->creature_stats_str->setValue(0);
    ui->creature_stats_dex->setValue(0);
    ui->creature_stats_mag->setValue(0);
    ui->creature_stats_int->setValue(0);
    ui->creature_stats_tra->setValue(0);
    ui->creature_stats_vel->setValue(0);
    ui->creature_stats_hp->setValue(0);
    ui->creature_stats_mana->setValue(0);

    ui->creature_spell_list->clear();
}

void adminControlForm::on_creatures_combobox_currentIndexChanged(const QString &arg1)
{
    QString creatureType = ui->creature_type_combobox->currentText();
    ui->creature_name->setText(arg1);
    QString currentMod = getCurrentMod();

    if (creatureType == "creature")
        setCurrentGender(creatures[arg1 + ":" + currentMod].gender);
    else if (creatureType == "prefix")
        setCurrentGender(prefixes[arg1 + ":" + currentMod].gender);
    else
        setCurrentGender(suffixes[arg1 + ":" + currentMod].gender);

    renderCreature(creatureType, currentMod, arg1);
}

void adminControlForm::on_creature_mod_currentIndexChanged(const QString &)
{
    QString creatureType = ui->creature_type_combobox->currentText();
    QString currentMod = getCurrentMod();
    if (creatureType == "creature")
        setCurrentGender(creatures[ui->creatures_combobox->currentText() + ":" + currentMod].gender);
    else if (creatureType == "prefix")
        setCurrentGender(prefixes[ui->creatures_combobox->currentText() + ":" + currentMod].gender);
    else
        setCurrentGender(suffixes[ui->creatures_combobox->currentText() + ":" + currentMod].gender);

    renderCreature(creatureType, currentMod, ui->creatures_combobox->currentText());
}

void adminControlForm::on_creature_gender_male_clicked()
{
    setCurrentGender("male");
}

void adminControlForm::on_creature_gender_female_clicked()
{
    setCurrentGender("female");
}

void adminControlForm::on_creature_gender_na_clicked()
{
    setCurrentGender("na");
}

void adminControlForm::on_creature_spell_add_clicked()
{
    QString spellDesc = ui->creature_spell_combobox->currentText();
    if (ui->creature_spell_list->findItems(spellDesc,Qt::MatchCaseSensitive).empty())
    {
        ui->creature_spell_list->addItem(spellDesc);

        SpellDescriptor sd;
        QStringList spellDescTokens = spellDesc.split(":");
        sd.spell_class = spellDescTokens.at(0);
        sd.spell_name = spellDescTokens.at(1);
        if (ui->creature_type_combobox->currentText() == "creature")
            creatureSpells[ui->creatures_combobox->currentText()].append(sd);
        else if (ui->creature_type_combobox->currentText() == "prefix")
            prefixSpells[ui->creatures_combobox->currentText()].append(sd);
        else if (ui->creature_type_combobox->currentText() == "suffix")
            suffixSpells[ui->creatures_combobox->currentText()].append(sd);

        saveCreatureSpellAction();
    }
}

void adminControlForm::on_creature_spell_save_clicked()
{
    QString prevItem;
    if (ui->creature_spell_list->currentRow() != -1 &&
        ui->creature_spell_list->findItems(ui->creature_spell_combobox->currentText(),Qt::MatchCaseSensitive).empty())
    {
        prevItem = ui->creature_spell_list->currentItem()->text();

        if (ui->creature_type_combobox->currentText() == "creature")
        {
            foreach (const SpellDescriptor& sd, creatureSpells[ui->creatures_combobox->currentText()])
                if (sd.spell_class + ":" + sd.spell_name == prevItem)
                    creatureSpells[ui->creatures_combobox->currentText()].removeOne(sd);
        }

        else if (ui->creature_type_combobox->currentText() == "prefix")
        {
            foreach (const SpellDescriptor& sd, creatureSpells[ui->creatures_combobox->currentText()])
                if (sd.spell_class + ":" + sd.spell_name == prevItem)
                    prefixSpells[ui->creatures_combobox->currentText()].removeOne(sd);
        }

        else if (ui->creature_type_combobox->currentText() == "suffix")
        {
            foreach (const SpellDescriptor& sd, creatureSpells[ui->creatures_combobox->currentText()])
                if (sd.spell_class + ":" + sd.spell_name == prevItem)
                    suffixSpells[ui->creatures_combobox->currentText()].removeOne(sd);
        }
        updateCreatureSpellAction();


    }
}

void adminControlForm::on_creature_spell_remove_clicked()
{
    QString prevItem;
    if (ui->creature_spell_list->currentRow() != -1)
    {
        prevItem = ui->creature_spell_list->currentItem()->text();
        QStringList itemTokens = prevItem.split(":");
        SpellDescriptor sd;
        sd.spell_class = itemTokens.at(0);
        sd.spell_name = itemTokens.at(1);
        delete ui->creature_spell_list->takeItem(ui->creature_spell_list->currentRow());
        if (ui->creature_type_combobox->currentText() == "creature")
            creatureSpells[ui->creatures_combobox->currentText()].removeAll(sd);
        else if (ui->creature_type_combobox->currentText() == "prefix")
            prefixSpells[ui->creatures_combobox->currentText()].removeAll(sd);
        else if (ui->creature_type_combobox->currentText() == "suffix")
            suffixSpells[ui->creatures_combobox->currentText()].removeAll(sd);
        removeCreatureSpellAction();
    }
}

void adminControlForm::on_creature_type_combobox_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "creature")
    {
        ui->creature_mod->clear();
        ui->creature_mod->setEditable(false);

        QString currentGender = getCurrentGender();
        for(QMap<QString, QString>::iterator it = mods[currentGender].begin(); it!= mods[currentGender].end(); ++it)
        {
            ui->creature_mod->addItem(it.key());
        }
    }
    else
    {
        ui->creature_mod->clear();
        ui->creature_mod->setEditable(true);
        QString creatureName = ui->creatures_combobox->currentText();
        if (ui->creature_type_combobox->currentText() == "prefix")
            for (QHash<QString, CreatureDescriptor>::iterator it = prefixes.begin(); it != prefixes.end(); ++it)
            {
                if (it.key() == creatureName && (it.value().creatureType == ui->creature_type_combobox->currentText()))
                    ui->creature_mod->addItem(it.value().mod);
            }
        else
            for (QHash<QString, CreatureDescriptor>::iterator it = suffixes.begin(); it != suffixes.end(); ++it)
            {
                if (it.key() == creatureName && (it.value().creatureType == ui->creature_type_combobox->currentText()))
                    ui->creature_mod->addItem(it.value().mod);
            }
        renderCreature(ui->creature_type_combobox->currentText(),ui->creature_mod->currentText(),ui->creatures_combobox->currentText());
    }
}
