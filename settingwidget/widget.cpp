#include "widget.h"

#include "fancytabwidget.h"
#include "pages/generalpage.h"
#include "pages/gitpage.h"
#include "pages/integrationpage.h"
#include "pages/updatepage.h"
#include "pages/custompage.h"
#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    ,settingPages(new FancyTabWidget(this))
{
    QWidget *page = new generalPage();
    QIcon  icon(":/icon/fork_64.205457463884px_1217079_easyicon.net.png");
    QString title("General");

    int index = -1;
    settingPages->insertTab(++index,page,icon,title);

    icon = QIcon(":/icon/git_logo_media_social_64px_1212972_easyicon.net.png");
    title = "Git";
    page = new gitPage();
    settingPages->insertTab(++index,page,icon,title);

    icon = QIcon(":/icon/graph_64.144144144144px_1194479_easyicon.net.png");
    title = "Custom";
    page = new customPage();
    settingPages->insertTab(++index,page,icon,title);

    icon = QIcon(":/icon/terminal_64px_1188177_easyicon.net.png");
    title = "Setting";
    page = new integrationPage();
    settingPages->insertTab(++index,page,icon,title);

    icon = QIcon(":/icon/update_64.467153284672px_1143807_easyicon.net.png");
    title = "Update";
    page = new updatePage();
    settingPages->insertTab(++index,page,icon,title);

    QHBoxLayout *hbox = new QHBoxLayout;

    hbox->addWidget(settingPages);
    hbox->setContentsMargins(0,0,0,0);

    setLayout(hbox);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *e)
{
    setFixedSize(this->width(),this->height());
}

