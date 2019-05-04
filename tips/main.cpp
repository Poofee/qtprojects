#include "mainwindow.h"
#include "qcalltip.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QCallTip* tip = new QCallTip();

    return a.exec();
}
