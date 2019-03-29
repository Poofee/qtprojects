#include "mainwindow.h"
#include <QApplication>

#include <QMap>
#include <qDebug>
#include <QHash>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /** QMap **/
    QMap<QString, int> map;
    map.insert("test 2", 2);
    map.insert("test 1", 7);
    map.insert("test 0", 0);

    for(int i = 0; i< 3; ++i){
        qDebug()<<map.value("test " + QString::number(i));
    }
    /** key是经过排序的 **/
    QList<QString> list = map.keys();
    for(int i = 0; i < 3; ++i){
        qDebug() << list[i];
    }
    /** QHash **/
    QHash<QString, int> hash;

    hash["key 2"] = 2;
    hash["key 1"] = 1;
    hash["key 0"] = 0;

    QHash<QString, int>::const_iterator i;

    for(i =  hash.constBegin(); i != hash.constEnd(); ++i){
        qDebug()<<i.key()<<" : "<<i.value();
    }
    return a.exec();
}
