#ifndef JSONPACK_H
#define JSONPACK_H

#include <QJsonObject>
#include <QString>

class JsonPack
{
public:
    explicit JsonPack();
    ~JsonPack();

    QJsonObject packRegister(const QString &, const QString &);
private:
    QJsonObject js;
};

#endif // JSONPACK_H
