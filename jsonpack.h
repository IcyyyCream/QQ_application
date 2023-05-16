#ifndef JSONPACK_H
#define JSONPACK_H

#include <QJsonObject>
#include <QString>

class JsonPack
{
public:
    explicit JsonPack();
    ~JsonPack();

    static QJsonObject packRegister(const QString &, const QString &);
private:
};

#endif // JSONPACK_H
