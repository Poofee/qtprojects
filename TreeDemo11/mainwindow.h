#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void InitTree();

private slots:
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* mModel;
    QSortFilterProxyModel* mProxyModel;
};

#endif // MAINWINDOW_H
