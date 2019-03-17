#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "mylibrary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Mylibrary lib;
    qDebug()<<lib.calc(2,30);
}

MainWindow::~MainWindow()
{
    delete ui;
}
