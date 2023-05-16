#include "widget.h"
#include "ui_widget.h"
#include "register.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbRegister, &QPushButton::clicked, this, &Widget::goRegister);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::goRegister()
{
    Register *reg = new Register(this);
    this->hide();
    reg->show();

    connect(reg, &Register::registerBack, this, [=](){
        reg->hide();
        this->show();
    });
}






