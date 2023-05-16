#include "register.h"
#include "ui_register.h"

#include <QMessageBox>
#include <QDebug>
#include <string>

const QString ip = "114.115.166.37";
const int port = 8000;

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(ip, port);
    connect(ui->pbBack, &QPushButton::clicked, this, &Register::registerBack);
    connect(ui->pbRegister, &QPushButton::clicked, this, &Register::sentRegInfo);

}

Register::~Register()
{
    delete ui;
    tcpSocket->abort();
}

void Register::sentRegInfo()
{
    if (ui->leAccount->text() == "")
    {
        QMessageBox::information(this, "警告", "用户名不能为空", QMessageBox::Warning);
    }
    else if (ui->lePassword1->text() == "")
    {
        QMessageBox::information(this, "警告", "密码不能为空", QMessageBox::Warning);
    }
    else if (ui->lePassword1->text() != ui->lePassword2->text())
    {
        QMessageBox::information(this, "警告", "两次输入的密码不相同", QMessageBox::Warning);
    }
    else
    {
        QString usr = ui->leAccount->text();
        QString password = ui->lePassword1->text();

        std::string message = QString("{\"cmd\": \"register\", \"user\": \"%1\", \"password\": \"%2\"}").arg(usr).arg(password).toStdString();
        // qDebug().noquote() << message.c_str();
        tcpSocket->write(message.c_str());
        tcpSocket->flush();
    }

}
