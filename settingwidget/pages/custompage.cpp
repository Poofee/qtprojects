#include "custompage.h"

#include <QPainter>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPixmapCache>
#include <QDebug>
#include <QLabel>

customPage::customPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *mylabel = new QLabel("customPage");

    vbox->addWidget(mylabel);
    setLayout(vbox);
}
