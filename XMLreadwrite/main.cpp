#include "widget.h"
#include "persistentsettings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    PersistentSettingsReader *reader = new PersistentSettingsReader();
    /** 相对路径生成绝对路径（shadowbuild） **/
    QString appPath = QApplication::applicationDirPath();
    QString fileName("/../../XMLreadwrite/XMLreadwrite.pro.user");
    fileName = appPath + fileName;
    reader->load(fileName);

    return a.exec();
}
