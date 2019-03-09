#include "integrationpage.h"

#include <QPainter>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPixmapCache>
#include <QDebug>
#include <QLabel>

integrationPage::integrationPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *mylabel = new QLabel("integrationPage");

    vbox->addWidget(mylabel);
    setLayout(vbox);
}
