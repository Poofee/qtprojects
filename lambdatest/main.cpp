#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug()<<"Start lambda test....";
    qDebug()<<[](int a, int b){return a+b;} (3,4);
    auto&& glambda = [](int a, int b) {return a+b;};
    qDebug()<<glambda(5,6);

    return a.exec();
}
