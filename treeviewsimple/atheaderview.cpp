#include "atheaderview.h"

#include <QMouseEvent>
#include <QPainter>

ATHeaderView::ATHeaderView(QWidget *parent):
    QHeaderView(Qt::Horizontal,parent)
{
    m_state = Qt::Unchecked;
    m_is_pressed = false;

    setSectionsClickable(true);
}

void ATHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter,rect,logicalIndex);//绘制其他Section
    painter->restore();

    //绘制背景色
    painter->save();
    painter->setBrush(QBrush(Qt::gray));
    painter->setPen(Qt::NoPen);
    painter->drawRect(rect);
    //绘制Section的Text
    painter->setFont(QFont("SimSun", 12));
    painter->setPen(QColor("#000000"));
    painter->drawText(rect, Qt::AlignCenter, model()->headerData(logicalIndex,Qt::Horizontal).toString());
    painter->restore();
    //为第一列绘制Checkbox
    if(logicalIndex == 0)
    {
        QStyleOptionButton option;
        option.initFrom(this);
        if(m_state == Qt::Unchecked)
        {
            option.state |= QStyle::State_Off;
        }
        else if(m_state == Qt::PartiallyChecked)
        {
            option.state |= QStyle::State_NoChange;
        }
        else if(m_state == Qt::Checked)
        {
            option.state |= QStyle::State_On;
        }
        option.iconSize = QSize(20, 20);
        option.rect = QRect(QPoint(rect.left()+5,rect.top()+(rect.height()-20)/2),QPoint(rect.left()+25,rect.bottom()-(rect.height()-20)/2));
        style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
    }
}

void ATHeaderView::mousePressEvent(QMouseEvent *e)
{
    int nColumn = logicalIndexAt(e->pos());
    if ((e->buttons() & Qt::LeftButton) && (nColumn == 0))
    {
        m_is_pressed = true;

        e->accept();
    }
    e->ignore();
}

void ATHeaderView::mouseReleaseEvent(QMouseEvent *e)
{
    if(m_is_pressed)
    {
        if(m_state == Qt::Unchecked)
        {
            m_state = Qt::Checked;
        }else
        {
            m_state = Qt::Unchecked;
        }
        updateSection(0);
        emit stateChanged(m_state); //状态改变
    }
    m_is_pressed = false;
    e->accept();
}
/**根据Item的复选框状态，表头复选框状态更新**/
void ATHeaderView::slot_stateChanged(Qt::CheckState state)
{
    m_state = state;

    updateSection(0);
}
