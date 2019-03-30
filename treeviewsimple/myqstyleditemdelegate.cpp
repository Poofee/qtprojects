#include "myqstyleditemdelegate.h"

#include <QPainter>

MyQStyledItemDelegate::MyQStyledItemDelegate(QObject *parent)
    :QStyledItemDelegate (parent)
{

}

void MyQStyledItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem itemOption(option);

    bool bSelected = false;
    if (itemOption.state & QStyle::State_HasFocus)
    {
        itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
    }
    if (itemOption.state & QStyle::State_MouseOver)
    {
        itemOption.state = itemOption.state ^ QStyle::State_MouseOver;
    }
    if (itemOption.state & QStyle::State_Selected)
    {
        bSelected = true;
        itemOption.state = itemOption.state ^ QStyle::State_Selected;
    }
    QStyledItemDelegate::paint(painter, itemOption, index);

    //画选中的行的框
    if(bSelected)
    {
        QRect rc = option.rect;
        painter->setPen( QPen(QColor("#F0F000"),1,Qt::SolidLine) ); //#00BFFF
        painter->drawLine(rc.topLeft(), rc.topRight());             //上下横线
        painter->drawLine(rc.bottomLeft(), rc.bottomRight());
        if( index.column() == 0 )
        {
            painter->drawLine(rc.topLeft(), rc.bottomLeft());       //左竖线
        }
        else
        {
            QModelIndex next = index.sibling(index.row(),index.column()+1); //右竖线
            if(!next.isValid())
            {
                painter->drawLine(rc.topRight(), rc.bottomRight());
            }
        }
    }
}
