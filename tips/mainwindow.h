#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent* e);
    void paintEvent(QPaintEvent* e);
private:
    QLabel* la = nullptr;
    QPainterPath geo;
    QList<QPainterPath> paths;
    bool inGeo;
    QColor selected;
    QColor noSelected;
    QColor toSelect;
    QColor deSelect;
    int currentIndex;
};

#endif // MAINWINDOW_H
