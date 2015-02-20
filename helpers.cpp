#include "helpers.h"



QString currentUserInfo::toString()
{
    return "Server: " + server + " Logined as " + group + " \'" + login + "\' [" + apikey + "] using hero \'" + heroName +
           "\' [" + heroHash + "]";
}
