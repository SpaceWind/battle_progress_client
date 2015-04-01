#include "helpers.h"



QString currentUserInfo::toString()
{
    return "Server: " + server + " Logined as " + group + " \'" + login + "\' [" + apikey + "] using hero \'" + heroName +
           "\' [" + heroHash + "]";
}


jsonParser::jsonParser(QByteArray data)
{
    jDoc = QJsonDocument::fromJson(data);
}

jsonParser::~jsonParser()
{

}

QStringList jsonParser::get(QString selector, QString defaultValue)
{
    QStringList result;
    QStringList tokens = getSelectorTokens(selector);
    QJsonObject root = jDoc.object();
    state = OBJECT_STATE;

    QJsonObject currentObject = root;
    QJsonArray currentArray;
    QJsonValue currentValue;
    QList<QJsonObject> arrayObjects;
    QList<QJsonValue> arrayValues;

    foreach (const QString& token, tokens)
    {
        if (token == "")
            continue;
        if (token == ".")
        {
            if (state == VALUE_STATE)
            {
                currentObject = currentValue.toObject();
                state = OBJECT_STATE;
            }
            else if (state == VALUES_ARRAY)
            {
                arrayObjects.clear();
                for (int valIndex=0; valIndex<currentArray.count(); valIndex++)
                    arrayObjects.append(currentArray.at(valIndex).toObject());
                state = OBJECTS_ARRAY;
            }
            else return result;

        }
        else if (token == "[")
        {
            if (state == VALUE_STATE)
            {
                currentArray = currentValue.toArray();
                state = ARRAY_STATE;
            }
            else return result;
        }
        else if (token == "]")
        {
            if (state == ARRAY_STATE)
            {
                arrayValues.clear();
                for (int valIndex=0; valIndex<currentArray.count(); valIndex++)
                    arrayValues.append(currentArray.at(valIndex));
                state = VALUES_ARRAY;
            }
            else if (state == VALUE_STATE)
            {
                ;
            }
            else return result;
        }
        else
        {
            bool isInt = false;
            int index = token.toInt(&isInt);
            if (state == ARRAY_STATE)
            {
                if (isInt && index>=0 && index < currentArray.count())
                {
                    currentValue = currentArray.at(index);
                    state = VALUE_STATE;
                }
            }
            else if (state == OBJECT_STATE)
            {
                currentValue = currentObject[token];
                state = VALUE_STATE;
            }
            else if (state == OBJECTS_ARRAY)
            {
                for (int valIndex=0; valIndex<arrayObjects.count(); valIndex++)
                    arrayValues.append(arrayObjects.at(valIndex)[token]);
                state = VALUES_ARRAY;
            }
            else return result;
        }
    }
    switch (state)
    {
    case VALUE_STATE:
        result.append(valueToString(currentValue, defaultValue));
        break;
    case VALUES_ARRAY:
        for (int i=0; i<arrayValues.count(); ++i)
            result.append(valueToString(arrayValues.at(i), defaultValue));
        break;
    default:
        break;
    }
    return result;
}

int jsonParser::getInt(QString selector)
{
    return get(selector, "-1").at(0).toInt();
}

bool jsonParser::getBool(QString selector)
{
    return (get(selector, "false").at(0).toLower() == "true") ? true : false;
}

QString jsonParser::first(QString selector)
{
    return get(selector).first();
}

QStringList jsonParser::getSelectorTokens(QString selector)
{
    selector = selector.simplified().replace(" ","").replace("]", " ] ").replace("["," [ ").replace("."," . ").replace("["," [ ");
    return selector.split(" ");
}

QString jsonParser::valueToString(QJsonValue value, QString defaultValue)
{
    switch (value.type())
    {
    case QJsonValue::Bool:
        if (value.toBool() == true)
            return "true";
        else return "false";
        break;
    case QJsonValue::Double:
        return QString::number(value.toDouble());
        break;
    case QJsonValue::String:
        return value.toString(defaultValue);
    default:
        return defaultValue;
    }
}


classSpecsDesc::classSpecsDesc()
{
    str = dex = mag = intellect = tra = vel = mana = hp = 0;
}

classSpecsDesc classSpecsDesc::fromString(QString s)
{
    QStringList tokens = s.split(";");
    classSpecsDesc result;
    foreach (const QString& str, tokens)
    {
        QStringList tokenItems = str.split(" ");
        if (str.indexOf("str") == 0)
            result.str = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("dex") == 0)
            result.dex = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("mag") == 0)
            result.mag = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("int") == 0)
            result.intellect = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("tra") == 0)
            result.tra = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("vel") == 0)
            result.vel = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("hp") == 0)
            result.hp = tokenItems.at(1).toInt();
        else if (str.simplified().indexOf("mana") == 0)
            result.mana = tokenItems.at(1).toInt();
    }
    return result;
}
