#ifndef HEROPREVIEWWINDOW_H
#define HEROPREVIEWWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QHash>
#include <QByteArray>
#include "gameserver.h"
#include "helpers.h"


namespace Ui {
class heroPreviewWindow;
}

class loadFullHeroInfoResponser : public ActionResponser
{
    Q_OBJECT
public slots:
    void processResponse(QByteArray response);
};

class heroPreviewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit heroPreviewWindow(QWidget *parent = 0);
    ~heroPreviewWindow();

    void setUser(currentUserInfo user){currentUser = user;}
public slots:
    void useHeroAction();
    void useHeroResponse(QByteArray response);
    void loadFullHeroInfoAction();
    void loadFullHeroInfoResponse(QByteArray response);

private:
    Ui::heroPreviewWindow *ui;
    currentUserInfo currentUser;
};

#endif // HEROPREVIEWWINDOW_H
