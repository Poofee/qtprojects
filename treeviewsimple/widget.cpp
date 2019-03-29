#include "widget.h"
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    ,treeView(new QTreeView())
{
    /**1，构造Model，这里示例具有3层关系的model构造过程**/
    mModel = new QStandardItemModel(treeView);
    mModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Number") << QStringLiteral("Name"));
    for(int i=0;i<5;i++)
    {
        /**一级节点，加入mModel**/
        QList<QStandardItem*> items1;
        QStandardItem* item1 = new QStandardItem(QString::number(i));
        QStandardItem* item2 = new QStandardItem(QStringLiteral("1"));
        items1.append(item1);
        items1.append(item2);
        mModel->appendRow(items1);

        for(int j=0;j<5;j++)
        {
            /**二级节点,加入第1个一级节点**/
            QList<QStandardItem*> items2;
            QStandardItem* item3 = new QStandardItem(QString::number(j));
            QStandardItem* item4 = new QStandardItem(QStringLiteral("2"));
            items2.append(item3);
            items2.append(item4);
            item1->appendRow(items2);

            for(int k=0;k<5;k++)
            {
                /**三级节点,加入第1个二级节点**/
                QList<QStandardItem*> items3;
                QStandardItem* item5 = new QStandardItem(QString::number(k));
                QStandardItem* item6 = new QStandardItem(QStringLiteral("3"));
                items3.append(item5);
                items3.append(item6);
                item3->appendRow(items3);
            }
        }
    }
    /**2，给QTreeView应用model**/
    treeView->setModel(mModel);

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(treeView);
    this->setLayout(hbox);

    /** connect函数得放在此处，放在前面的话因为变量还没有被生成，所以无效 **/
    connect(treeView->selectionModel(),&QItemSelectionModel::selectionChanged,this,&Widget::slotSelectionChanged);
    connect(treeView->selectionModel(),&QItemSelectionModel::currentChanged,this,&Widget::slotCurrentChanged);
    connect(treeView->selectionModel(),&QItemSelectionModel::currentRowChanged,this,&Widget::slotCurrentRowChanged);
}

Widget::~Widget()
{

}

/**选中内容变化，覆盖单选和多选的情况**/
void Widget::slotSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QItemSelectionModel *selections = treeView->selectionModel();
    QModelIndexList indexes = selections->selectedIndexes();    /**得到所有选中的index**/
    qDebug()<<Q_FUNC_INFO;
    foreach(QModelIndex index, indexes)
    {
        /**从索引index获取item指针,mModel是tree的数据Model,这里是QStandardItemModel*类型**/
        QStandardItem* item = mModel->itemFromIndex(index);
        if (item)
        {
            /**你的操作,比如取文本、取附带的data**/
            QString text = item->text();
            QString data1 = item->data(Qt::UserRole + 1).toString();
//            QString data2 = item->data(Qt::UserRole + 2).toInt();
            qDebug()<<text<<data1;
        }
    }
}

/**当前选中index变化，单个**/
void Widget::slotCurrentChanged(const QModelIndex &t, const QModelIndex &previous)
{
    QStandardItem* item = mModel->itemFromIndex(t);
    if (item)
    {

    }
}

/**当前选中行变化，单行**/
void Widget::slotCurrentRowChanged(const QModelIndex &t, const QModelIndex &previous)
{
    //取选中的这行的第一个元素的index
    QModelIndex index = t.sibling(t.row(),0);
    QStandardItem* item = mModel->itemFromIndex(index);
    if(item)
    {

    }
}
