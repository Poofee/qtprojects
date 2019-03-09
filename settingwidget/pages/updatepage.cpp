#include "updatepage.h"

#include <QPainter>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPixmapCache>
#include <QDebug>
#include <QLabel>

updatePage::updatePage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *mylabel = new QLabel("update");

    vbox->addWidget(mylabel);
    setLayout(vbox);
}
