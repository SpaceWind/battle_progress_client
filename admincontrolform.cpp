#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QTime>
#include <QTimer>

#include "admincontrolform.h"
#include "ui_admincontrolform.h"

adminControlForm::adminControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminControlForm)
{
    ui->setupUi(this);
    server = 0;
    lastDescIndex = 0;
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
        if (!isFound)
            QMessageBox::information(this,"Class was not found","Class was not found!");
        ui->status_label->setText(parser.first("status"));
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
    ui->status_label->setText("Loading relations...");
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
                hostileTokens = hostile.split(";");
            if (!friendly.isEmpty())
                friendlyTokens = friendly.split(";");
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
                hostileStr += ";";
        }
        else if (item == "friendly")
        {
            friendlyStr += factions.at(i);
            if (i != factions.count()-1)
                friendlyStr += ";";
        }
    }
    params["h"] = hostileStr;
    params["f"] = friendlyStr;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(saveFactionRelationsResponse(QByteArray)));
    server->call("admin createRelation",params);
    ui->status_label->setText("Saving relations...");
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
void adminControlForm::on_pushButton_clicked()
{
    searchHeroesForLoginAction(ui->lineEdit->text(), currentUser.apikey);
}

void adminControlForm::on_found_heroes_currentIndexChanged(int index)
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
    lastFactionInfoName = factions.at(0);
    getFactionRelationsAction(lastFactionInfoName);
}

void adminControlForm::on_pushButton_6_clicked()
{
    lastFactionInfoName = factions.at(0);
    saveFactionRelationsAction(lastFactionInfoName);
}
