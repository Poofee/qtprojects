#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
