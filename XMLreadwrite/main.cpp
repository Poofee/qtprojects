#include "widget.h"
#include "persistentsettings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    PersistentSettingsReader *reader = new PersistentSettingsReader();
    QString fileName("../../XMLreadwrite/XMLreadwrite.pro.user");
    reader->load(fileName);

    return a.exec();
}
