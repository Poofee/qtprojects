#include "welcomepagebutton.h"
#include <QHBoxLayout>
#include <QLabel>

//static QPalette buttonPalette(bool isActive, bool isCursorInside, bool forText)
//{
//    QPalette pal;
//    Theme *theme = Utils::creatorTheme();
//    if (isActive) {
//        if (forText) {
//            pal.setColor(QPalette::Background, theme->color(Theme::Welcome_ForegroundPrimaryColor));
//            pal.setColor(QPalette::Foreground, theme->color(Theme::Welcome_ForegroundPrimaryColor));
//            pal.setColor(QPalette::WindowText, theme->color(Theme::Welcome_BackgroundColor));
//        } else {
//            pal.setColor(QPalette::Background, theme->color(Theme::Welcome_ForegroundPrimaryColor));
//            pal.setColor(QPalette::Foreground, theme->color(Theme::Welcome_ForegroundPrimaryColor));
//        }
//    } else {
//        if (isCursorInside) {
//            if (forText) {
//                pal.setColor(QPalette::Background, theme->color(Theme::Welcome_HoverColor));
//                pal.setColor(QPalette::Foreground, theme->color(Theme::Welcome_HoverColor));
//                pal.setColor(QPalette::WindowText, theme->color(Theme::Welcome_TextColor));
//            } else {
//                pal.setColor(QPalette::Background, theme->color(Theme::Welcome_HoverColor));
//                pal.setColor(QPalette::Foreground, theme->color(Theme::Welcome_ForegroundSecondaryColor));
//            }
//        } else {
//            if (forText) {
//                pal.setColor(QPalette::Background, theme->color(Theme::Welcome_ForegroundPrimaryColor));
//                pal.setColor(QPalette::Foreground, theme->color(Theme::Welcome_BackgroundColor));
//                pal.setColor(QPalette::WindowText, theme->color(Theme::Welcome_TextColor));
//            } else {
//                pal.setColor(QPalette::Background, theme->color(Theme::Welcome_BackgroundColor));
//                pal.setColor(QPalette::Foreground, theme->color(Theme::Welcome_ForegroundSecondaryColor));
//            }
//        }
//    }
//    return pal;
//}

class WelcomePageButtonPrivate
{
public:
    WelcomePageButtonPrivate(WelcomePageButton *parent) : q(parent) {}
    bool isActive() const;
    void doUpdate(bool cursorInside);

    WelcomePageButton *q;
    QHBoxLayout *m_layout = nullptr;
    QLabel *m_label = nullptr;
    QLabel *m_icon = nullptr;

    //std::function<void()> onClicked;
    //std::function<bool()> activeChecker;
};

WelcomePageButton::WelcomePageButton(QWidget *parent)
    : WelcomePageFrame(parent), d(new WelcomePageButtonPrivate(this))
{
    setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::yellow);
    pal.setColor(QPalette::Foreground, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::red);

    setPalette(pal);


    QFont f = font();
    f.setPixelSize(15);
    d->m_label = new QLabel(this);
    d->m_label->setFont(f);

    pal.setColor(QPalette::Background, Qt::white);
    pal.setColor(QPalette::Foreground, Qt::black);

    d->m_label->setPalette(pal);

    d->m_layout = new QHBoxLayout;
    d->m_layout->setContentsMargins(13, 5, 20, 5);
    d->m_layout->setSpacing(0);
    d->m_layout->addWidget(d->m_label);
    setLayout(d->m_layout);
}

WelcomePageButton::~WelcomePageButton()
{
    delete d;
}

void WelcomePageButton::mousePressEvent(QMouseEvent *)
{

}

void WelcomePageButton::enterEvent(QEvent *)
{

}

void WelcomePageButton::leaveEvent(QEvent *)
{

}

void WelcomePageButton::setText(const QString &text)
{
    d->m_label->setText(text);
}

//void WelcomePageButtonPrivate::doUpdate(bool cursorInside)
//{
//    const bool active = isActive();
//    q->setPalette(buttonPalette(active, cursorInside, false));
//    const QPalette lpal = buttonPalette(active, cursorInside, true);
//    m_label->setPalette(lpal);
//    if (m_icon)
//        m_icon->setPalette(lpal);
//    q->update();
//}
