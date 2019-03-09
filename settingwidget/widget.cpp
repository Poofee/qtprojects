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

    int index = 0;
    settingPages->insertTab(index,page,icon,title);

    FancyTabBar *bar = new FancyTabBar(this);
    bar->insertTab(0,icon,title);


    QHBoxLayout *hbox = new QHBoxLayout;

//    QLabel *mylabel = new QLabel("general");


//    hbox->addWidget(mylabel);
    hbox->addWidget(settingPages);
//    hbox->addWidget(bar);
//    bar->show();

    setLayout(hbox);
}

Widget::~Widget()
{

}

