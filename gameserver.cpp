#include "gameserver.h"

GameServer::GameServer(QString serverURL, QObject *parent) : QObject(parent)
{
    server = serverURL;
    manager = 0;
}

void GameServer::call(QString method, QHash<QString, QString> params)
{
    if (manager)
        delete manager;
    manager = new QNetworkAccessManager(this);
    QUrl url(server);
    QUrlQuery query;

    for(QHash<QString, QString>::iterator i = params.begin(); i != params.end(); ++i)
        query.addQueryItem(i.key(),i.value());

    url.setPath("/" + method);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());



    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(request);

}

GameServer::~GameServer()
{
    delete manager;
}

void GameServer::replyFinished(QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        emit callFinished(QString("!!:HTTP ERROR: " + reply->errorString()).toUtf8());
    }
    else
    {
        emit callFinished(reply->readAll());
    }
}

