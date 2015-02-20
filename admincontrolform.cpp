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
}

void adminControlForm::setUser(currentUserInfo &info)
{
    currentUser = info;
    if (server)
        delete server;
    server = new GameServer(info.server);
}

adminControlForm::~adminControlForm()
{
    delete ui;
}

void adminControlForm::searchHeroesForLoginResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!");
    else
    {
        QJsonDocument jDoc = QJsonDocument::fromJson(response);
        QJsonObject root = jDoc.object();

        QJsonValue success = root.value("success");
        QJsonValue status = root.value("status");

        if (success.type() == QJsonValue::Bool && success.toBool())
        {
            QJsonValue heroesValue = root.value("heroes");
            QJsonValue namesValue = root.value("names");
            QJsonValue lvlsValue = root.value("lvls");
            QJsonValue racesValue = root.value("races");
            QJsonValue factionValue = root.value("factions");

            QJsonArray heroes = heroesValue.toArray();
            QJsonArray names = namesValue.toArray();
            QJsonArray lvls = lvlsValue.toArray();
            QJsonArray races = racesValue.toArray();
            QJsonArray factions = factionValue.toArray();

            foundHeroes.clear();
            ui->found_heroes->clear();
            for (int i=0; i<heroes.count(); i++)
            {
                heroDescriptor_Min currentHero;
                currentHero.hash = heroes[i].toString();
                currentHero.lvl = lvls[i].toInt();
                currentHero.race = races[i].toString();
                currentHero.faction = factions[i].toString();
                foundHeroes[names[i].toString()] = currentHero;
                ui->found_heroes->addItem(names[i].toString());
            }
            if (heroes.count() != 0)
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

void adminControlForm::on_pushButton_clicked()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["login"] = ui->lineEdit->text();
    params["apikey"] = currentUser.apikey;

    server->disconnect();
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(searchHeroesForLoginResponse(QByteArray)));

    server->call("admin heroes",params);
    ui->pushButton->setEnabled(false);
    ui->status_label->setText("Searching for heroes...");
}
