#ifndef WELCOMEPAGEBUTTON_H
#define WELCOMEPAGEBUTTON_H

#include "welcomepageframe.h"

class WelcomePageButtonPrivate;

class WelcomePageButton : public WelcomePageFrame
{
public:
    WelcomePageButton(QWidget *parent);
    ~WelcomePageButton() override;

    void mousePressEvent(QMouseEvent *) override;
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;

    void setText(const QString &text);
    //void setIcon(const QPixmap &pixmap);
    //void setOnClicked(const std::function<void ()> &value);
    //void setActiveChecker(const std::function<bool ()> &value);
    //void recheckActive();
    void click();

private:
    WelcomePageButtonPrivate *d;
};

#endif // WELCOMEPAGEBUTTON_H
