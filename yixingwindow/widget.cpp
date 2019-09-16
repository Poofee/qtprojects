#include "widget.h"

#include <QBitmap>
#include <QPixmap>
#include <QDebug>
#include <QPalette>
#include <QPaintEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent,Qt::FramelessWindowHint)
{
    //让程序背景半透明
    this->setWindowOpacity(0.8);
    //加载一幅有部分区域是透明的图片作为程序的界面
    if(!m_Pixmap.load(":/img/hudie"))
        qDebug()<<"fail load";
    resize(700, 690);
    //保持图片跟界面一样大小
    m_Pixmap = m_Pixmap.scaled(size());
    //设置自动填充
    setAutoFillBackground(true);

    //不规则窗口的关键，将图片透明的地方设为穿透
    setMask( m_Pixmap.mask() );

    setMouseTracking(true);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,m_Pixmap);
    this->setPalette(bgPalette);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    // this->xOffset 和 this->yOffset 是成员变量，因为mouseMoveEvent函数也要用到
    this->xOffset = event->globalPos().rx() - this->pos().rx();
    this->yOffset = event->globalPos().ry() - this->pos().ry();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) {// 这个if 判断只是为了保证是按压鼠标左键移动产生窗体拖动效果
        this->move(event->globalX()-this->xOffset,event->globalY()-this->yOffset);
    }
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->close();
}
