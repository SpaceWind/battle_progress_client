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
    ~GameServer();

signals:
   void callFinished(QByteArray result);
public slots:
   void replyFinished (QNetworkReply *reply);
private:
    QNetworkAccessManager *manager;
    QString server;
};

#endif // GAMESERVER_H
