#ifndef MYTAB_H
#define MYTAB_H

#include <QWidget>

class QLabel;

class MyTab : public QWidget
{
    Q_OBJECT
public:
    MyTab(QWidget *parent, const QString img, const QString title);
    ~MyTab();

signals:

public slots:

public:
    QLabel *m_icon;
    QLabel *m_text;
};

#endif // MYTAB_H
