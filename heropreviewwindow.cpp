#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include "heropreviewwindow.h"
#include "ui_heropreviewwindow.h"

heroPreviewWindow::heroPreviewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heroPreviewWindow)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(-5, -5);
    effect->setColor(Qt::yellow);
    ui->manabar->setGraphicsEffect(effect);
}

heroPreviewWindow::~heroPreviewWindow()
{
    delete ui;
}

void heroPreviewWindow::useHeroAction()
{
    GameServer * server = new GameServer(currentUser.server);

    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    params["heroid"] = currentUser.heroHash;
    server->call("hero use", params);
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(useHeroResponse(QByteArray)));
    this->setWindowOpacity(0.0);
    ui->status_line->setText("Connecting to server...");
}

void heroPreviewWindow::useHeroResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            QTimer::singleShot(150,this,SLOT(loadFullHeroInfoAction()));
            ui->status_line->setText("OK");
        }
        else
            ui->status_line->setText("ERROR: " + parser.first("status"));
    }
}

void heroPreviewWindow::loadFullHeroInfoAction()
{
    GameServer * server = new GameServer(currentUser.server);

    QHash<QString, QString> params;
    params["apikey"] = currentUser.apikey;
    server->call("hero preview", params);
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(loadFullHeroInfoResponse(QByteArray)));
    ui->status_line->setText("Loading hero info");
}

void heroPreviewWindow::loadFullHeroInfoResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_line->setText("CONNECTION UNAVAILABLE!");
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            this->setWindowTitle("Hero Preview    [" + parser.first("owner") + " : " + parser.first("desc.hero_name") + "]");
            ui->label_name->setText("Name: " + parser.first("desc.hero_name"));
            ui->label_owner->setText("Owner: " + parser.first("owner"));
            ui->label_class->setText("Class: " + parser.first("desc.hclass"));
            ui->label_faction->setText("Faction: " + parser.first("desc.hrace"));
            ui->label_level->setText("Level: " + QString::number(parser.getInt("desc.lvl")));

            ui->label_str->setText("STR: "+QString::number(parser.getInt("stats.str")) + "[" + QString::number(double(parser.getInt("stats.start_str"))/10.).mid(0,3) + "]");
            ui->label_dex->setText("DEX: "+QString::number(parser.getInt("stats.dex")) + "[" + QString::number(double(parser.getInt("stats.start_dex"))/10.).mid(0,3) + "]");
            ui->label_mag->setText("MAG: "+QString::number(parser.getInt("stats.mag")) + "[" + QString::number(double(parser.getInt("stats.start_mag"))/10.).mid(0,3) + "]");
            ui->label_int->setText("INT: "+QString::number(parser.getInt("stats.int")) + "[" + QString::number(double(parser.getInt("stats.start_int"))/10.).mid(0,3) + "]");
            ui->label_tra->setText("TRA: "+QString::number(parser.getInt("stats.tra")) + "[" + QString::number(double(parser.getInt("stats.start_tra"))/10.).mid(0,3) + "]");
            ui->label_vel->setText("VEL: "+QString::number(parser.getInt("stats.vel")) + "[" + QString::number(double(parser.getInt("stats.start_vel"))/10.).mid(0,3) + "]");
            ui->label_hp->setText("HP: "+QString::number(parser.getInt("stats.max_hp"))   + "[" + QString::number(double(parser.getInt("stats.start_hp"))/10.).mid(0,3) + "]");
            ui->label_mana->setText("MANA: "+QString::number(parser.getInt("stats.max_mana")) + "[" + QString::number(double(parser.getInt("stats.start_mana"))/10.).mid(0,3) + "]");

            ui->inventar_box->setTitle("Items: [" + QString::number(parser.getInt("inventar_count")) + "/" + QString::number(parser.getInt("desc.pack_max_size")) + "]");

            ui->hpbar->setMaximum(parser.getInt("stats.max_hp"));
            ui->manabar->setMaximum(parser.getInt("stats.max_mana"));
            ui->hpbar->setValue(parser.getInt("stats.current_hp"));
            ui->manabar->setValue(parser.getInt("stats.current_mana"));

            ui->expbar->setMaximum(parser.getInt("desc.exp_to_next_lvl"));
            ui->expbar->setValue(parser.getInt("desc.experience"));


            ui->moodbar->setMaximum(1000);
            int mood = parser.getInt("desc.mood");
            if (mood <= 0)
                ui->moodbar->setStyleSheet("QProgressBar::chunk {\n     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(198, 60, 2, 236), stop:0.318182 rgba(255, 255, 255, 248), stop:0.505682 rgba(255, 175, 158, 255), stop:0.977273 rgba(151, 12, 0, 221));\n     width: 1px;\n }\n\n QProgressBar {\n     border: 2px solid grey;\n     border-radius: 5px;\n     text-align: center;\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(255, 230, 230, 221), stop:1 rgba(156, 123, 123, 255));\n	color: #FF3;\n	font-weight: bold;\n     text-align: center;\n }");
            else
                ui->moodbar->setStyleSheet("QProgressBar::chunk {\n     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(2, 140, 198, 236), stop:0.318182 rgba(255, 255, 255, 248), stop:0.505682 rgba(158, 223, 255, 255), stop:0.977273 rgba(0, 81, 151, 221));\n     width: 1px;\n }\n\n QProgressBar {\n     border: 2px solid grey;\n     border-radius: 5px;\n     text-align: center;\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(255, 230, 230, 221), stop:1 rgba(156, 123, 123, 255));\n	color: #FF3;\n	font-weight: bold;\n     text-align: center;\n }");

            ui->moodbar->setValue(mood);
            ui->status_line->setText("OK");
        }
        else
            ui->status_line->setText("ERROR: " + parser.first("status"));
    }
    this->setWindowOpacity(1);
}


void loadFullHeroInfoResponser::processResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        return;
}
