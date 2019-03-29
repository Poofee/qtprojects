#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include "TreeModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化模拟数据：学生成绩
    //10个班级、每个班级10000个学生，共10W行记录
    int nClass = 10;
    int nStudent = 10000;
    for(int i=0;i<nClass;i++)
    {
        CLASS* c = new CLASS;
        c->name = QString("class%1").arg(i);
        for(int j=0;j<nStudent;j++)
        {
            STUDENT* s = new STUDENT;
            s->name = QString("name%1").arg(j);
            s->score1 = s->score2 = s->score3 = (j%10)*10;
            c->students.append(s);
        }
        mClasses.append(c);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn1_clicked()
{
    //1，QTreeView常用设置项
    QTreeView* t = ui->treeView;
//    t->setEditTriggers(QTreeView::NoEditTriggers);			//单元格不能编辑
    t->setSelectionBehavior(QTreeView::SelectRows);			//一次选中整行
    t->setSelectionMode(QTreeView::SingleSelection);        //单选，配合上面的整行就是一次选单行
//    t->setAlternatingRowColors(true);                       //每间隔一行颜色不一样，当有qss时该属性无效
    t->setFocusPolicy(Qt::NoFocus);                         //去掉鼠标移到单元格上时的虚线框

    //2，列头相关设置
    t->header()->setHighlightSections(true);                //列头点击时字体变粗，去掉该效果
    t->header()->setDefaultAlignment(Qt::AlignCenter);      //列头文字默认居中对齐
    t->header()->setDefaultSectionSize(100);                //默认列宽100
    t->header()->setStretchLastSection(true);               //最后一列自适应宽度
    t->header()->setSortIndicator(0,Qt::AscendingOrder);    //按第1列升序排序

    //3，构造Model
    QStringList headers;
    headers << QStringLiteral("班级/姓名")
            << QStringLiteral("语文")
            << QStringLiteral("数学")
            << QStringLiteral("外语")
            << QStringLiteral("总分")
            << QStringLiteral("平均分")
            << QStringLiteral("是否合格")
            << QStringLiteral("是否评优");
    QStandardItemModel* model = new QStandardItemModel(ui->treeView);
    model->setHorizontalHeaderLabels(headers);

    foreach (CLASS* c, mClasses)
    {
        //一级节点：班级
        QStandardItem* itemClass = new QStandardItem(c->name);
        model->appendRow(itemClass);

        foreach (STUDENT* s, c->students)
        {
            //二级节点：学生信息
            int score1 = s->score1;
            int score2 = s->score2;
            int score3 = s->score3;
            int nTotal = score1 + score2 + score3;
            int nAverage = nTotal/3;
            bool bPass = true;
            if(score1 < 60 || score2 < 60 || score3 < 60)
            {
                //任意一门课不合格则不合格
                bPass = false;
            }
            bool bGood = false;
            if(score1 >= 90 && score2 >= 90 && score3 >= 90)
            {
                //每门课都达到90分以上评优
                bGood = true;
            }

            QList<QStandardItem*> items;
            QStandardItem* item0 = new QStandardItem(s->name);
            QStandardItem* item1 = new QStandardItem(QString::number(score1));
            QStandardItem* item2 = new QStandardItem(QString::number(score2));
            QStandardItem* item3 = new QStandardItem(QString::number(score3));
            QStandardItem* item4 = new QStandardItem(QString::number(nTotal));
            QStandardItem* item5 = new QStandardItem(QString::number(nAverage));
            QStandardItem* item6 = new QStandardItem(bPass ? QStringLiteral("合格") : QStringLiteral("不合格"));
            QStandardItem* item7 = new QStandardItem(bGood ? QStringLiteral("优秀") : QStringLiteral("-"));
            items << item0 << item1 << item2 << item3 << item4 << item5 << item6 << item7;
            itemClass->appendRow(items);
        }
    }

    //4，应用model
    t->setModel(model);
}

void MainWindow::on_btn2_clicked()
{
    //1，QTreeView常用设置项
    QTreeView* t = ui->treeView;
//    t->setEditTriggers(QTreeView::NoEditTriggers);			//单元格不能编辑
    t->setSelectionBehavior(QTreeView::SelectRows);			//一次选中整行
    t->setSelectionMode(QTreeView::SingleSelection);        //单选，配合上面的整行就是一次选单行
//    t->setAlternatingRowColors(true);                       //每间隔一行颜色不一样，当有qss时该属性无效
    t->setFocusPolicy(Qt::NoFocus);                         //去掉鼠标移到单元格上时的虚线框

    //2，列头相关设置
    t->header()->setHighlightSections(true);                //列头点击时字体变粗，去掉该效果
    t->header()->setDefaultAlignment(Qt::AlignCenter);      //列头文字默认居中对齐
    t->header()->setDefaultSectionSize(100);                //默认列宽100
    t->header()->setStretchLastSection(true);               //最后一列自适应宽度
    t->header()->setSortIndicator(0,Qt::AscendingOrder);    //按第1列升序排序

    //3，构造Model
    QStringList headers;
    headers << QStringLiteral("班级/姓名")
            << QStringLiteral("语文")
            << QStringLiteral("数学")
            << QStringLiteral("外语")
            << QStringLiteral("总分")
            << QStringLiteral("平均分")
            << QStringLiteral("是否合格")
            << QStringLiteral("是否评优");
    //注意：此时构造的是自定义的TreeModel！
    TreeModel* model = new TreeModel(headers,ui->treeView);

    TreeItem* root = model->root();
    foreach (CLASS* c, mClasses)
    {
        //一级节点：班级
        TreeItem* itemClass = new TreeItem(root);
        itemClass->setLevel(1);     //设为一级节点，供显示时判断节点层级来转换数据指针类型
        itemClass->setPtr(c);       //保存CLASS* c为其数据指针，显示时从该CLASS*取内容显示
        root->appendChild(itemClass);

        foreach (STUDENT* s, c->students)
        {
            TreeItem* itemStudent = new TreeItem(itemClass);
            itemStudent->setLevel(2);   //设为一级节点，供显示时判断节点层级来转换数据指针类型
            itemStudent->setPtr(s);     //保存STUDENT* s为其数据指针，显示时从STUDENT*取内容显示
            itemClass->appendChild(itemStudent);
        }
    }
    //4，应用model
    t->setModel(model);
}
