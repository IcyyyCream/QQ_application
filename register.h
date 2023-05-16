#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void sentRegInfo();

signals:
    void registerBack();

private:
    Ui::Register *ui;
    QTcpSocket *tcpSocket;
};

#endif // REGISTER_H
