#include "widget.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    // 设置编码格式为utf8
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    // test git
    return a.exec();
}
