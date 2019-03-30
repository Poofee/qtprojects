#ifndef MYTREEVIEW_H
#define MYTREEVIEW_H

#include <QTreeView>

class MyTreeView : public QTreeView
{
    Q_OBJECT
public:
    MyTreeView(QWidget* parent);

protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // MYTREEVIEW_H
