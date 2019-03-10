#ifndef WELCOMEPAGEFRAME_H
#define WELCOMEPAGEFRAME_H

#include <QWidget>

class WelcomePageFrame : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomePageFrame(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;
signals:

public slots:
};

#endif // WELCOMEPAGEFRAME_H
