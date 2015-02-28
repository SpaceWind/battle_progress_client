#include "newherodialog.h"
#include "ui_newherodialog.h"
#include <QTimer>
#include <QMessageBox>

newHeroDialog::newHeroDialog(currentUserInfo c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newHeroDialog)
{
    ui->setupUi(this);
    currentUser = c;
    setEnabled(false);
    QTimer::singleShot(150,this,SLOT(getFactionsAction()));
    server = new GameServer(c.server);
}

newHeroDialog::~newHeroDialog()
{
    delete ui;
}

void newHeroDialog::getFactionsAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getFactionsResponse(QByteArray)));

    server->call("meta factions",params);
    ui->pushButton->setEnabled(false);
    ui->status_label->setText("Searching for factions...");
}

void newHeroDialog::getFactionsResponse(QByteArray response)
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
            ui->faction_combobox->addItems(factions);
            QTimer::singleShot(150,this,SLOT(getClassesAction()));
        }
        ui->status_label->setText(parser.first("status"));
    }
    ui->pushButton->setEnabled(true);
}

void newHeroDialog::getClassesAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(getClassesResponse(QByteArray)));
    server->call("meta classes",params);
    ui->status_label->setText("Loading class...");
}

void newHeroDialog::getClassesResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        classes = parser.get("classes[]");
        ui->class_combobox->clear();
        ui->class_combobox->addItems(classes);
        classesInfo.clear();
        for (int i=0; i< classes.count(); ++i)
        {
            classDescriptor_Min desc;
            desc.lib_imp = parser.first("lib_imp["+QString::number(i)+"]");
            desc.lib_rop = parser.first("lib_rop["+QString::number(i)+"]");
            desc.lib_dap = parser.first("lib_dap["+QString::number(i)+"]");
            desc.lib_vip = parser.first("lib_vip["+QString::number(i)+"]");
            desc.lib_tvp = parser.first("lib_tvp["+QString::number(i)+"]");
            desc.lib_prp = parser.first("lib_prp["+QString::number(i)+"]");
            classesInfo[classes.at(i)] = desc;
        }
        ui->status_label->setText(parser.first("status"));
        this->setEnabled(true);
    }
}

void newHeroDialog::rollHeroAction()
{
    if (server)
    {
        delete server;
        server = new GameServer(currentUser.server);
    }
    QHash<QString, QString> params;
    params["class_name"] = ui->class_combobox->currentText();
    params["apikey"] = currentUser.apikey;
    if (ui->gender_combobox->currentIndex() == 1)
        params["gender"] = "female";

    QObject::connect(server,SIGNAL(callFinished(QByteArray)),this,SLOT(rollHeroResponse(QByteArray)));

    server->call("hero.roll",params);
    ui->pushButton->setEnabled(false);
    ui->status_label->setText("Searching for factions...");
}

void newHeroDialog::rollHeroResponse(QByteArray response)
{
    if (response.indexOf("!!:HTTP") == 0)
        ui->status_label->setText("CONNECTION UNAVAILABLE!" + QString(response.toStdString().c_str()));
    else
    {
        jsonParser parser(response);
        if (parser.getBool("success"))
        {
            originalText = parser.first("desc");
            ui->hero_desc->setHtml(buildDescString());
            setBg(parser.getInt("quality"));
        }
        ui->status_label->setText(parser.first("status"));
    }
    ui->pushButton->setEnabled(true);
}

QString newHeroDialog::buildDescString()
{
    QString result = originalText;
    result.replace("%h",ui->hero_name->text());
    result.replace("%c.imp",classesInfo[ui->class_combobox->currentText()].lib_imp);
    result.replace("%c.rop",classesInfo[ui->class_combobox->currentText()].lib_rop);
    result.replace("%c.dap",classesInfo[ui->class_combobox->currentText()].lib_dap);
    result.replace("%c.vip",classesInfo[ui->class_combobox->currentText()].lib_vip);
    result.replace("%c.tvp",classesInfo[ui->class_combobox->currentText()].lib_tvp);
    result.replace("%c.prp",classesInfo[ui->class_combobox->currentText()].lib_prp);
    return result;

}

void newHeroDialog::setBg(int opLevel)
{
    if (opLevel < -9)
        ui->hero_desc->setStyleSheet("background-color: #EEEEEE;\nbackground: qlineargradient(spread:reflect, x1:0.41, y1:0.68, x2:0.264, y2:0.861, stop:0 rgba(140, 95, 60, 120), stop:1 rgba(210, 180, 160, 255));\n\n");
    else if (opLevel < 0)
        ui->hero_desc->setStyleSheet("background-color: #EEEEEE;\nbackground: qlineargradient(spread:reflect, x1:0.43, y1:0.67, x2:0.204, y2:0.841, stop:0 rgba(170, 130, 78, 110), stop:1 rgba(255, 255, 255, 255));\n\n");
    else if (opLevel <= 7)
        ui->hero_desc->setStyleSheet("background-color: #EEEEEE;\nbackground: qlineargradient(spread:reflect, x1:0.53, y1:0.57, x2:0.224, y2:0.821, stop:0 rgba(160, 160, 180, 100), stop:1 rgba(255, 255, 255, 255));\n\n");
    else if (opLevel <= 10)
        ui->hero_desc->setStyleSheet("background-color: #EEEEEE;\nbackground: qlineargradient(spread:reflect, x1:0.63, y1:0.47, x2:0.244, y2:0.801, stop:0 rgba(220, 190, 60, 90), stop:1 rgba(255, 255, 220, 255));\n\n");
    else if (opLevel <= 13)
        ui->hero_desc->setStyleSheet("background-color: #EEEEEE;\nbackground: qlineargradient(spread:reflect, x1:0.63, y1:0.47, x2:0.244, y2:0.801, stop:0 rgba(60, 210, 242, 100), stop:1 rgba(230, 255, 255, 255));\n\n");
    else
        ui->hero_desc->setStyleSheet("background-color: #EEEEEE;\nbackground: qlineargradient(spread:reflect, x1:0.63, y1:0.47, x2:0.244, y2:0.801, stop:0 rgba(120, 220, 120, 100), stop:1 rgba(240, 255, 220, 255));\n\n");

    if (opLevel <=13)
        QTimer::singleShot(150,this,SLOT(on_pushButton_clicked()));
}

void newHeroDialog::on_hero_name_textChanged(const QString &arg1)
{
    ui->hero_desc->setHtml(buildDescString());
}

void newHeroDialog::on_pushButton_clicked()
{
    rollHeroAction();
}
