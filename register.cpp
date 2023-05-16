#include "register.h"
#include "ui_register.h"

#include <QMessageBox>
#include <QDebug>
#include <QString>

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    connect(ui->pbBack, &QPushButton::clicked, this, &Register::registerBack);
    connect(ui->pbRegister, &QPushButton::clicked, this, &Register::sentRegInfo);
}

Register::~Register()
{
    delete ui;
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
        qDebug() <<  "用户名" << usr;
        qDebug() <<  "密码" << password;
    }

}
