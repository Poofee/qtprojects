#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<Q_FUNC_INFO;
}

Widget::~Widget()
{

}
