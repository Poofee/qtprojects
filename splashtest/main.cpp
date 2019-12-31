#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /** 欢迎页面 **/
    QSplashScreen* splash = new QSplashScreen;

    QPixmap pixmap(":/splash.png");
    splash->setPixmap(pixmap);
    splash->setAttribute(Qt::WA_DeleteOnClose);
    splash->show();
    splash->showMessage(QObject::tr("Loading..."),
                        Qt::AlignRight|Qt::AlignBottom,Qt::black);
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
    } while (n.secsTo(now)<=1);//6 为需要延时的秒数
    splash->raise();
    splash->showMessage(QObject::tr("Loading..."),
                        Qt::AlignRight|Qt::AlignBottom,Qt::black);

    splash->finish(&w);
    delete splash;
    w.show();

    return a.exec();
}
