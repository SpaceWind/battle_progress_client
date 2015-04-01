#ifndef NEWHERODIALOG_H
#define NEWHERODIALOG_H

#include <QDialog>
#include <QList>
#include <QHash>
#include <QStringList>
#include "gameserver.h"
#include "helpers.h"

namespace Ui {
class newHeroDialog;
}

struct classDescriptor_Min
{
    QString lib_imp, lib_rop, lib_dap, lib_vip, lib_tvp, lib_prp;
};

class newHeroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newHeroDialog(currentUserInfo c, QWidget *parent = 0);
    ~newHeroDialog();
public slots:

    void getFactionsAction();
    void getFactionsResponse(QByteArray response);
    void getClassesAction();
    void getClassesResponse(QByteArray response);

    void rollHeroAction();
    void rollHeroResponse(QByteArray response);

    void saveRolledChampAction();
    void saveRolledChampResponse(QByteArray response);

private slots:
    void on_hero_name_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_saveButton_clicked();

private:
    QString buildDescString();

    void setBg(int opLevel);

    Ui::newHeroDialog *ui;
    QString class_name, lib_imp, lib_rop, lib_dap, lib_vip, lib_tvp, lib_prp;
    QString originalText;
    currentUserInfo currentUser;
    QStringList factions;
    QStringList classes;
    QHash<QString, classDescriptor_Min> classesInfo;

    GameServer* server;
};

#endif // NEWHERODIALOG_H
