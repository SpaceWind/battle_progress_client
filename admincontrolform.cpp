#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QInputDialog>
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

void adminControlForm::searchFactionsActions()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;

    server->disconnect();
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
    QTimer::singleShot(500,this,SLOT(searchFactionsActions()));
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
            races.clear();
            races.append(parser.get("factions[]"));
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
    ui->status_label->setText("Creating new class...");
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
    params["person_name"] = name;
    params["lib_imp"] = imp;
    params["lib_rop"] = rop;
    params["lib_dap"] = dap;
    params["lib_vip"] = vip;
    params["lib_tvp"] = tvp;
    params["lib_prp"] = prp;

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(newClassResponse(QByteArray)));

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

void adminControlForm::saveDescAction(QString name, QString item)
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QString text = ui->class_desc->toPlainText();
    if (lastDescIndex>= text.length())
    {
        ui->status_label->setText("OK");
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
       // ui->status_label->setText(parser.first("status"));
    }
}

void adminControlForm::resaveDesc()
{
    saveDescAction(lastDescName, lastDescItem);
}

void adminControlForm::on_pushButton_clicked()
{
    searchHeroesForLoginAction(ui->lineEdit->text(), currentUser.apikey);
}

void adminControlForm::on_found_heroes_currentIndexChanged(int index)
{
   // ui->class_combobox->setCurrentText(foundHeroes[ui->found_heroes->currentText()].race);
    ui->faction_combobox->setCurrentText(foundHeroes[ui->found_heroes->currentText()].faction);
    ui->level_label->setText(QString::number(foundHeroes[ui->found_heroes->currentText()].lvl));
}

void adminControlForm::on_pushButton_4_clicked()
{

}

void adminControlForm::on_pushButton_5_clicked()
{
    newClassAction(ui->class_name->text(),
                   currentUser.apikey,
                   ui->class_imp->text(), ui->class_rop->text(), ui->class_dap->text(),
                   ui->class_vip->text(), ui->class_tvp->text(), ui->class_prp->text());
}
