#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    widget* mywidget = new widget(this);
//    mywidget->setWindowFlags(mywidget->windowFlags()|Qt::Dialog);//设置子窗口属性

//    mywidget->setParent(this);//设置依附的窗口
    mywidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
