#include "loginregisterdialog.h"
#include "ui_loginregisterdialog.h"
#include "gameserver.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QInputDialog>
#include <QDir>
#include <QTime>
#include <QTimer>

LoginRegisterDialog::LoginRegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginRegisterDialog)
{
    ui->setupUi(this);
    server = 0;
    ui->login_password->setEchoMode(ui->login_password->Password);
    ui->register_password->setEchoMode(ui->register_password->Password);
    setResult(this->Rejected);
}

LoginRegisterDialog::~LoginRegisterDialog()
{
    delete ui;
}

void LoginRegisterDialog::checkUserAction(QString login)
{
    if (server)
        delete server;
    server = new GameServer(ui->register_server->text());

    QHash<QString, QString> params;
    params["login"] = login;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(checkUserResponse(QByteArray)));
    server->call("userExists",params);
}

void LoginRegisterDialog::pingServerAction()
{
    if (server)
        delete server;
    server = new GameServer(ui->register_server->text());

    QHash<QString, QString> params;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(pingServerResponse(QByteArray)));
    server->call("ping",params);
}

void LoginRegisterDialog::pingServerResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->register_server->setStyleSheet("background-color: #FF9999;");
    else
        ui->register_server->setStyleSheet("background-color: #99FF99;");
    QTimer::singleShot(100,this,SLOT(on_register_nickname_editingFinished()));
}

void LoginRegisterDialog::getHeroes()
{
    ui->pushButton_2->setEnabled(false);
    if (server)
        delete server;
    server = new GameServer(ui->register_server->text());

    QHash<QString, QString> params;
    params["apikey"] = apikey;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(searchHeroesResponse(QByteArray)));
    server->call("heroes",params);
    ui->status_line->setText("Searching for heroes!");
}



void LoginRegisterDialog::on_pushButton_clicked()
{
    //here goes register proc
    if (server)
        delete server;
    server = new GameServer(ui->register_server->text());

    QHash<QString, QString> params;
    params["login"] = ui->register_nickname->text();
    params["pass"] = ui->register_password->text();

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(registrationResponse(QByteArray)));
    server->call("signup",params);
    ui->status_line->setText("Connecting to server");
    ui->pushButton->setEnabled(false);

}

void LoginRegisterDialog::on_pushButton_2_clicked()
{
    //here goes login proc
    if (server)
        delete server;
    server = new GameServer(ui->login_server->text());

    QHash<QString, QString> params;
    params["login"] = ui->login_nickname->text();
    params["pass"] = ui->login_password->text();

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(loginResponse(QByteArray)));
    server->call("login",params);
    ui->status_line->setText("Connecting to server");
    ui->pushButton_2->setEnabled(false);
    ui->heroes->setEnabled(false);
    ui->connect_button->setEnabled(false);
    ui->new_hero->setEnabled(false);
}


void LoginRegisterDialog::on_new_hero_clicked()
{
    QHash<QString, QString> params;
    params["login"] = ui->login_nickname->text();
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input hero Name"),
                                         tr("Hero name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
        params["name"] = text;
        QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(newHeroResponse(QByteArray)));
        server->call("temphero",params);
        ui->status_line->setText("Creating new hero!");
        ui->pushButton_2->setEnabled(false);
    }
    else
        ui->status_line->setText("Cannot create Hero without the name!");
}
void LoginRegisterDialog::on_connect_button_clicked()
{
    this->accept();
}

void LoginRegisterDialog::registrationResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
    {
        QJsonDocument jDoc = QJsonDocument::fromJson(response);
        QJsonObject root = jDoc.object();
        QJsonValue success = root.value("success");
        QJsonValue status = root.value("status");
        if (success.type() == QJsonValue::Bool && success.toBool())
        {
            ui->status_line->setText("Registration Complete!");
        }
        else
            ui->status_line->setText("ERROR: " + status.toString("Reponse Incorrect"));
    }
    ui->pushButton->setEnabled(true);
}

void LoginRegisterDialog::loginResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
    {
        QJsonDocument jDoc = QJsonDocument::fromJson(response);
        QJsonObject root = jDoc.object();
        QJsonValue success = root.value("success");
        QJsonValue status = root.value("status");
        QJsonValue jApikey = root.value("apikey");
        QJsonValue jGroup = root.value("group");
        if (success.type() == QJsonValue::Bool && success.toBool())
        {
            ui->status_line->setText("Success: apikey = " + jApikey.toString("N/A"));
            apikey = jApikey.toString();
            serverUrl = ui->login_server->text();
            group = jGroup.toString("players");
            login = ui->login_nickname->text();
            QTimer::singleShot(1000,this,SLOT(getHeroes()));
        }
        else
            ui->status_line->setText("ERROR: " + status.toString("Reponse Incorrect"));
    }
    ui->pushButton_2->setEnabled(true);
}

void LoginRegisterDialog::searchHeroesResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
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

            QJsonArray heroes = heroesValue.toArray();
            QJsonArray names = namesValue.toArray();

            foundHeroes.clear();
            ui->heroes->clear();
            for (int i=0; i<heroes.count(); i++)
            {
                foundHeroes[names[i].toString()] = heroes[i].toString();
                ui->heroes->addItem(names[i].toString());
            }
            if (heroes.count() != 0)
            {
                chosenHeroHash = heroes[0].toString();
                chosenHeroName = names[0].toString();
                ui->heroes->setEnabled(true);
                ui->connect_button->setEnabled(true);
            }
            ui->new_hero->setEnabled(true);
            ui->status_line->setText("Success!");
        }
        else
            ui->status_line->setText("ERROR: " + status.toString("Reponse Incorrect"));
    }
    ui->pushButton_2->setEnabled(true);
}

void LoginRegisterDialog::newHeroResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
        QTimer::singleShot(1000,this,SLOT(getHeroes()));
    ui->pushButton_2->setEnabled(true);
}

void LoginRegisterDialog::checkUserResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
    {
        ui->register_nickname->setStyleSheet("");
    }
    else
    {
        QJsonDocument jDoc = QJsonDocument::fromJson(response);
        QJsonObject root = jDoc.object();

        QJsonValue success = root.value("success");
        QJsonValue exists = root.value("exists");

        if (success.type() == QJsonValue::Bool && success.toBool())
        {
            if (exists.toBool(true))
                ui->register_nickname->setStyleSheet("background-color: #FF9999");
            else
                ui->register_nickname->setStyleSheet("background-color: #99FF99");
        }
    }
    ui->pushButton_3->setEnabled(true);
}

void LoginRegisterDialog::on_register_server_returnPressed()
{
    ui->pushButton->click();
}

void LoginRegisterDialog::on_heroes_currentIndexChanged(const QString &arg1)
{
    chosenHeroName = arg1;
    chosenHeroHash = foundHeroes[arg1];
}


void LoginRegisterDialog::on_register_nickname_editingFinished()
{
    checkUserAction(ui->register_nickname->text());
}

void LoginRegisterDialog::on_pushButton_3_clicked()
{
    pingServerAction();
    ui->pushButton_3->setEnabled(false);
}
