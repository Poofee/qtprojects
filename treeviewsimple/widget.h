#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    void slotSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void slotCurrentChanged(const QModelIndex &t, const QModelIndex &previous);
    void slotCurrentRowChanged(const QModelIndex &t, const QModelIndex &previous);

    QTreeView* treeView;
    QStandardItemModel* mModel;
};

#endif // WIDGET_H
