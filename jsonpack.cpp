#include "jsonpack.h"

JsonPack::JsonPack()
{

}

JsonPack::~JsonPack()
{

}

QJsonObject JsonPack::packRegister(const QString &usrName, const QString &password)
{
    QJsonObject js;
    js.insert("cmd", "register");
    js.insert("usr", usrName);
    js.insert("password", password);

    return js;
}
