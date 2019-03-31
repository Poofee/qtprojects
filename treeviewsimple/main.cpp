#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(QApplication::desktop()->width()*0.8,QApplication::desktop()->height()*0.8);
    w.show();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);

//    QDesktopWidget* desktop = QApplication::desktop();
//    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    return a.exec();
}
