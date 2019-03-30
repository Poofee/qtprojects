#ifndef MYQSTYLEDITEMDELEGATE_H
#define MYQSTYLEDITEMDELEGATE_H


#include <QStyledItemDelegate>

class MyQStyledItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MyQStyledItemDelegate(QObject *parent = Q_NULLPTR);
    ~MyQStyledItemDelegate();

public:
    void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const;

private:

};
#endif // MYQSTYLEDITEMDELEGATE_H
