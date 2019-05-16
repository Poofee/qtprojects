#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>

class widget : public QDialog
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = nullptr);

    QWidget* createMagMaterialWidget();

signals:

public slots:
};

#endif // WIDGET_H
