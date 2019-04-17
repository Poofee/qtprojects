#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug()<<w.status.testFlag(MainWindow::FlagVisible);
    w.setVisible();
    qDebug()<<w.status.testFlag(MainWindow::FlagVisible);

    return a.exec();
}
