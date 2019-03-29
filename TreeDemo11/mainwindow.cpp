#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QSortFilterProxyModel>
#include "mydelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitTree()
{
    //1，QTreeView常用设置项
    QTreeView* t = ui->treeView;
//    t->setEditTriggers(QTreeView::NoEditTriggers);			//单元格不能编辑
    t->setSelectionBehavior(QTreeView::SelectRows);			//一次选中整行
    t->setSelectionMode(QTreeView::SingleSelection);        //单选，配合上面的整行就是一次选单行
//    t->setAlternatingRowColors(true);                       //每间隔一行颜色不一样，当有qss时该属性无效
    t->setFocusPolicy(Qt::NoFocus);                         //去掉鼠标移到单元格上时的虚线框

    MyDelegate* delegate = new MyDelegate;
    t->setItemDelegate(delegate);

    //2，列头相关设置
    t->header()->setHighlightSections(true);                //列头点击时字体变粗，去掉该效果
    t->header()->setDefaultAlignment(Qt::AlignCenter);      //列头文字默认居中对齐
    t->header()->setDefaultSectionSize(100);                //默认列宽100
    t->header()->setStretchLastSection(true);               //最后一列自适应宽度
    t->header()->setSortIndicator(0,Qt::AscendingOrder);    //按第1列升序排序

    //3，构造Model
    //设置列头
    QStringList headers;
    headers << QStringLiteral("年级/班级")
            << QStringLiteral("姓名")
            << QStringLiteral("分数")
            << QStringLiteral("评价");
    mModel = new QStandardItemModel(ui->treeView);
    mModel->setHorizontalHeaderLabels(headers);
    //设置数据
    QStringList names;
    names<<"aaa"<<"bbb"<<"ccc"<<"ddd"<<"eee"<<"abc"<<"abcdef";
    for(int i=0; i<names.size(); i++)
    {
        //二级节点：班级、姓名、分数
        QList<QStandardItem*> items;
        QStandardItem* itemClass = new QStandardItem(QStringLiteral("%1班").arg(i+1));
        QStandardItem* itemName = new QStandardItem(names.at(i));
        QStandardItem* itemScore = new QStandardItem("100");
        QStandardItem* itemAssess = new QStandardItem("优");
        items << itemClass << itemName << itemScore << itemAssess;
        mModel->appendRow(items);    //二级节点挂在一级的第1列节点上
    }
    //4，构造代理model,设置过滤列为第2列
    mProxyModel = new QSortFilterProxyModel;
    mProxyModel->setSourceModel(mModel);
    mProxyModel->setFilterKeyColumn(1);
    t->setModel(mProxyModel);
}

void MainWindow::on_btn1_clicked()
{
    //正则表达式
    //包含a、b、c中任意一个字符就满足
    QRegExp regExp("[abc]", Qt::CaseInsensitive, QRegExp::RegExp);
    mProxyModel->setFilterRegExp(regExp);
}

void MainWindow::on_btn2_clicked()
{
    //通配符
    //有bc的满足
    QRegExp regExp("bc*", Qt::CaseInsensitive, QRegExp::Wildcard);
    mProxyModel->setFilterRegExp(regExp);
}

void MainWindow::on_btn3_clicked()
{
    //文本
    //包含文本e的满足
    QRegExp regExp("e", Qt::CaseInsensitive, QRegExp::FixedString);
    mProxyModel->setFilterRegExp(regExp);
}

