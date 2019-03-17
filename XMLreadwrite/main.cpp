#include "widget.h"
#include "persistentsettings.h"

#include <QApplication>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    PersistentSettingsReader *reader = new PersistentSettingsReader();
    /** 相对路径生成绝对路径（shadowbuild） **/
    QString appPath = QApplication::applicationDirPath();
    QString fileName("/../XMLreadwrite/XMLreadwrite.pro.user");
    fileName = appPath + fileName;
    reader->load(fileName);

    //XMLwrite test
    QFileInfo fileInfo(fileName);
    QString w_fileName = fileInfo.path()+"/"+fileInfo.baseName()+"1."+fileInfo.completeSuffix();
    QVariantMap data = reader->restoreValues();

    QString errorMessage;
    QString docType("projects");
    PersistentSettingsWriter *m_writer = new PersistentSettingsWriter(w_fileName, docType);

    m_writer->save(data, &errorMessage);

    return a.exec();
}
