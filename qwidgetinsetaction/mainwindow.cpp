#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* testLabel = new QLabel(this);
    testLabel->setText("hello\ncccc");



    QAction* action1 = new QAction("action");
    testLabel->addAction(action1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
