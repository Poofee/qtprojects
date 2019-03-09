#include "gitpage.h"

#include <QPainter>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPixmapCache>
#include <QDebug>
#include <QLabel>

gitPage::gitPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *mylabel = new QLabel("gitPage");

    vbox->addWidget(mylabel);
    setLayout(vbox);
}
