#include "jsonpack.h"

JsonPack::JsonPack()
{

}

JsonPack::~JsonPack()
{

}

QJsonObject JsonPack::packRegister(const QString &usrName, const QString &password)
{
    this->js.insert("cmd", "register");
    this->js.insert("usr", usrName);
    this->js.insert("password", password);

    return *this;
}
