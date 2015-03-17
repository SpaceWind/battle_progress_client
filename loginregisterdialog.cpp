#include "loginregisterdialog.h"
#include "ui_loginregisterdialog.h"
#include "heropreviewwindow.h"

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
    setWindowTitle("Battle Progress!");
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
    currentUserInfo accountInfo;
    accountInfo.apikey = getKey();
    accountInfo.group = getGroup();
    accountInfo.server = getServerURL();
    accountInfo.heroHash = getHeroHash();
    accountInfo.heroName = getHeroName();
    accountInfo.login = getLogin();

    newHeroDialog diag(accountInfo);
    if (diag.exec())
    {
        QTimer::singleShot(100,this,SLOT(getHeroes()));
    }
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
        jsonParser parser(response);
        QString status = parser.first("status");
        if (parser.getBool("success"))
            ui->status_line->setText("Registration Complete!");
        else
            ui->status_line->setText("ERROR: " + status);
    }
    ui->pushButton->setEnabled(true);
}

void LoginRegisterDialog::loginResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            apikey = parser.first("apikey");
            ui->status_line->setText("Success: apikey = " + apikey);
            serverUrl = ui->login_server->text();
            group = parser.first("group");
            login = ui->login_nickname->text();
            QTimer::singleShot(200,this,SLOT(getHeroes()));
        }
        else
            ui->status_line->setText("ERROR: " + parser.first("status"));
    }
    ui->pushButton_2->setEnabled(true);
}

void LoginRegisterDialog::searchHeroesResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
    {
        jsonParser parser(response);
        QString status = parser.first("status");

        QStringList heroes = parser.get("heroes[]");
        QStringList names = parser.get("names[]");

        if (parser.getBool("success"))
        {
            foundHeroes.clear();
            for (int i=0; i< heroes.count(); ++i)
                foundHeroes[names[i]] = heroes[i];

            ui->heroes->clear();
            ui->heroes->addItems(names);

            if (heroes.count() != 0)
            {
                chosenHeroHash = heroes.first();
                chosenHeroName = names.first();
                ui->heroes->setEnabled(true);
                ui->connect_button->setEnabled(true);
                ui->view_button->setEnabled(true);
            }
            ui->new_hero->setEnabled(true);
            ui->status_line->setText("Success!");
        }
        else
            ui->status_line->setText("ERROR: " + status);
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
        ui->register_nickname->setStyleSheet("");
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            if (parser.getBool("exists"))
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

void LoginRegisterDialog::on_pushButton_4_clicked()
{

}

void LoginRegisterDialog::on_view_button_clicked()
{
    heroPreviewWindow heroPreview;
    currentUserInfo accountInfo;

    accountInfo.apikey = getKey();
    accountInfo.group = getGroup();
    accountInfo.server = getServerURL();
    accountInfo.heroHash = getHeroHash();
    accountInfo.heroName = getHeroName();
    accountInfo.login = getLogin();

    heroPreview.setWindowModality(Qt::WindowModal);
    heroPreview.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    heroPreview.setUser(accountInfo);
    heroPreview.useHeroAction();
    heroPreview.exec();
}
