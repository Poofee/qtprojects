#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class FancyTabWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public:
    FancyTabWidget *settingPages;
};

#endif // WIDGET_H
