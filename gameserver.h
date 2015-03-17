#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QSslConfiguration>
#include <QDateTime>

class GameServer : public QObject
{
    Q_OBJECT
public:
    explicit GameServer(QString serverURL, QObject *parent = 0);

    void call(QString method, QHash<QString, QString> params);
    void post(QString method, QHash<QString, QString> params);
    ~GameServer();

signals:
   void callFinished(QByteArray result);
public slots:
   void replyFinished (QNetworkReply *reply);
private:
    QNetworkAccessManager *manager;
    QString server;
};

class ActionResponser : public QObject
{
    Q_OBJECT
public slots:
    virtual void processResponse(QByteArray result)=0;
};

class ActionPerformer : public QObject
{
    Q_OBJECT
public:
    ActionPerformer(){alreadyCalled = false;}
    ~ActionPerformer(){delete gs;}

    void call(QString serverURL, QString method, QHash<QString, QString> params, ActionResponser* responser);
private:
    GameServer * gs;
    bool alreadyCalled;
};

#endif // GAMESERVER_H
