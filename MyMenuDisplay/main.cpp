#include "mainwindow.h"
#include <QApplication>
#include<QTextCodec>
#include<QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//实现显示中文
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    MainWindow w;
    w.show();

    return a.exec();
}
