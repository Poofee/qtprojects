#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

/**
 * @brief 测试dynamic_cast的功能
 *
 * @param argc
 * @param argv[]
 * @return int
 */

class A{
public:
    int num;
    virtual void add();
};
class B : public A{
public:
    int size;
    void add() override;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    A* a1 = new A();
    B* b1 = new B();

    qDebug()<<"dynamic_cast<A*>(a1)"<<dynamic_cast<A*>(a1);
    qDebug()<<"dynamic_cast<B*>(a1)"<<dynamic_cast<B*>(a1);
    qDebug()<<"dynamic_cast<B*>(b1)"<<dynamic_cast<B*>(b1);
    qDebug()<<"dynamic_cast<A*>(b1)"<<dynamic_cast<A*>(b1);

    return a.exec();
}

void A::add()
{
    qDebug()<<"add A";
}

void B::add()
{
    qDebug()<<"add B";
}
