#include "generalpage.h"

#include <QPainter>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPixmapCache>
#include <QDebug>
#include <QLabel>

generalPage::generalPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *mylabel = new QLabel("general");

    vbox->addWidget(mylabel);
    setLayout(vbox);
}
