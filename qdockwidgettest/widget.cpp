#include "widget.h"

#include <QDockWidget>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    QDockWidget* widget1 = new QDockWidget(this);
    QLabel* label1 = new QLabel("Label1");
    widget1->setWidget(label1);
    QDockWidget* widget2 = new QDockWidget(this);
    QLabel* label2 = new QLabel("label2");
    widget2->setWidget(label2);
    QDockWidget* widget3 = new QDockWidget(this);
    QLabel* label3 = new QLabel("label3");
    widget3->setWidget(label3);
    QDockWidget* widget4 = new QDockWidget(this);
    QLabel* label4 = new QLabel("label4");
    widget4->setWidget(label4);
    QDockWidget* widget5 = new QDockWidget(this);
    QLabel* label5 = new QLabel("label5");
    widget5->setWidget(label5);

    addDockWidget(Qt::LeftDockWidgetArea,widget1);
    addDockWidget(Qt::RightDockWidgetArea,widget2);
    addDockWidget(Qt::BottomDockWidgetArea,widget3);
    addDockWidget(Qt::TopDockWidgetArea,widget4);
    addDockWidget(Qt::BottomDockWidgetArea,widget5);
}

Widget::~Widget()
{

}
