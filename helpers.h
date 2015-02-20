#ifndef HELPERS_H
#define HELPERS_H
#include <QString>

struct currentUserInfo
{
    QString toString();
    QString login;
    QString apikey;
    QString heroName;
    QString heroHash;
    QString group;
    QString server;
};

struct heroDescriptor_Min
{
    QString hash;
    QString race;
    QString faction;
    int lvl;
};

#endif // HELPERS_H
