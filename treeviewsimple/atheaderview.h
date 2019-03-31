#ifndef ATHEADERVIEW_H
#define ATHEADERVIEW_H

#include <QHeaderView>

class ATHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit ATHeaderView(QWidget *parent = 0);
    ~ATHeaderView(){}
protected:
    virtual void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
signals:
    void stateChanged(Qt::CheckState state);
private slots:
    void slot_stateChanged(Qt::CheckState state);
private:
    Qt::CheckState m_state;
    bool m_is_pressed;
};

#endif // ATHEADERVIEW_H
