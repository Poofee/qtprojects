#include "welcomepageframe.h"
#include <QPalette>
#include <QPainter>

WelcomePageFrame::WelcomePageFrame(QWidget *parent) : QWidget(parent)
{
    setContentsMargins(1, 1, 1, 1);
}

void WelcomePageFrame::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    const QRectF adjustedRect(QRectF(rect()).adjusted(0.5, 0.5, -0.5, -0.5));
    QPen pen(palette().color(QPalette::WindowText));
    pen.setJoinStyle(Qt::MiterJoin);

    QPainter p(this);
    p.setPen(pen);
    p.drawRect(adjustedRect);
}
