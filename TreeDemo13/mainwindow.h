#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "define.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btn1_clicked(); //QStandardItemModel
    void on_btn2_clicked(); //自定义model

private:
    Ui::MainWindow *ui;
    QVector<CLASS*> mClasses;   //模拟数据
};

#endif // MAINWINDOW_H
