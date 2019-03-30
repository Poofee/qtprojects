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


private slots:
    void slotTreeMenu(const QPoint &pos);
    void slotTreeMenuExpand(bool checked = false);
    void slotTreeMenuCollapse(bool checked = false);

private:
    QTreeView* treeView;
    QStandardItemModel* mModel;
};

#endif // WIDGET_H
