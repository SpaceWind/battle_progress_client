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

    method = method.replace(".","/").replace("::","/").replace(":","/").replace(" ", "/");
    url.setPath("/" + method);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());



    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(request);
}

void GameServer::post(QString method, QHash<QString, QString> params)
{
    method = method.replace(".","/").replace("::","/").replace(":","/").replace(" ", "/");
    if (manager)
        delete manager;
    manager = new QNetworkAccessManager(this);

    QUrl url(server);
    url.setPath("/" + method);

    QUrlQuery query;

    for(QHash<QString, QString>::iterator i = params.begin(); i != params.end(); ++i)
        query.addQueryItem(i.key(),i.value());

    QNetworkRequest request(url);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->post(request,query.toString(QUrl::FullyEncoded).toUtf8());
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

