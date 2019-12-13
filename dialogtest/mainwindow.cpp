#include "mainwindow.h"

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>
#include <QSplitter>
#include <QPainter>

//QT 应用程序关闭某个窗口时，关闭打开的所有其他窗口并退出程序 【转】
//原文：http://blog.csdn.net/yangyunfeizj/article/details/7398023#

//项目中当关闭主窗口时，需要将同时打开的其他窗口关闭，并退出应用程序，实现方法如下：

//在main函数中将QApplication::lastWindowClosed()信号和QApplication::quit()
//槽函数相关联，将主窗口的属性设置为QWidget::setAttribute(WA_QuitOnClose,true);
//其他窗口该属性设置为false。
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget::setAttribute(Qt::WA_QuitOnClose,true);
    auto w = new MyWidget(this);
    setCentralWidget(w);
    QToolButton* okButton = new QToolButton(w);
    okButton->setText("OK");
    QToolButton cancelbt(w);/** 函数结束后被释放，无法显示 **/
    cancelbt.setText("Cancel");
//    okButton->setAutoRaise(true);
    QHBoxLayout* hbox = new QHBoxLayout(w);
    hbox->addWidget(okButton);
    hbox->addWidget(&cancelbt);
    w->setLayout(hbox);
}

MainWindow::~MainWindow()
{

}

void MainWindow::showDialog()
{
    auto d = new QWidget;
    d->setAttribute(Qt::WA_QuitOnClose,false);
    d->setWindowFlags(Qt::WindowStaysOnTopHint);
    d->show();

    auto dialog = new QDialog(this);
    auto pushbutton1 = new QPushButton(dialog);
    pushbutton1->setText("Button1");
    dialog->show();
}

MyWidget::MyWidget(QWidget *parent)
    :QWidget (parent)
{

}

MyWidget::~MyWidget()
{

}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    /**设置字体、大小、字符间距等**/
    QFont font;
    font.setPointSize(50);
//    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);
    p.setFont(font);
    /**获取这种字体情况下，文本的长度和高度**/
    QFontMetricsF fontMetrics(font);
    qreal wid = fontMetrics.width("FEEM");
    qreal height = fontMetrics.capHeight();

    p.drawLine(this->width()/2,0,this->width()/2,this->height());
    p.drawLine(0,this->height()/2,this->width(),this->height()/2);
    p.setPen(QPen(QColor(160,160,160)));
    /**文字画在（x，y）这个点的左边，（x，y）在文字的中间**/
    p.drawText(this->width()/2 -wid/2,this->height()/2 +height/2,"FEEM");
}
