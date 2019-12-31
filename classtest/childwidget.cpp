#include "childwidget.h"
#include <QDebug>

ChildWidget::ChildWidget()
{
    qDebug()<<Q_FUNC_INFO;
}

ChildWidget::ChildWidget(QString name)
{
    qDebug()<<Q_FUNC_INFO;
}
