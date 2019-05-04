#include "mytreeview.h"
#include <QDebug>
#include <QApplication>
#include <QMouseEvent>

MyTreeView::MyTreeView(QWidget *parent)
    :QTreeView (parent)
{

}

void MyTreeView::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<Q_FUNC_INFO;
    if( e->button() == Qt::LeftButton )          //是否左键按下
    {
        QModelIndex index = indexAt(e->pos());  //取出按下点的元素索引index
        if( index.isValid() )                   //判断index是否有效
        {
            //你的处理
            QVariant data = index.data(Qt::UserRole+1);
            qDebug()<<index.data().toString()<<index.row();

//            if(!isExpanded(index))
//                expand(index);
//            else
//                collapse(index);
        }


        /**如果需要判断组合键，使用下面代码**/
        if(QApplication::keyboardModifiers () == Qt::ControlModifier)
        {
            //当前CTRL是否按下,根据需要加此情况
        }
        else if(QApplication::keyboardModifiers() == Qt::ShiftModifier)
        {
            //当前SHIFT是否按下,根据需要加此情况
        }
        else
        {
            //只是左键按下，没有CTRL和SHIFT
            //你的处理...
        }
    }
}

void MyTreeView::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<Q_FUNC_INFO;
}

void MyTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<Q_FUNC_INFO;

    QModelIndex curIndex = currentIndex();
    QModelIndex index = curIndex;//.sibling(curIndex.row(),0); //同一行第一列元素的index
    if(index.isValid())
    {
        qDebug()<<"expanding..."<<curIndex.row();
        if(!isExpanded(index))
            expand(index);
        else
            collapse(index);
    }
}

void MyTreeView::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<Q_FUNC_INFO;
}
