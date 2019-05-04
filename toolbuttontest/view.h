#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

class QToolBar;

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = 0);
    ~View();
    void init();

private:
    QToolBar* toolBar;
    QAction* zoom;
    QAction* zoomextents;
    QAction* zoomin;
    QAction* zoomout;
    QAction* zoomselected;
};

#endif // VIEW_H
