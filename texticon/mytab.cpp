#include "mytab.h"

#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>

MyTab::MyTab(QWidget *parent, QString const imgpath, QString const title)
    : QWidget(parent)
    ,m_icon(new QLabel())
    ,m_text(new QLabel())
{
   m_text->setText(title);
   QPixmap *img = new QPixmap(imgpath);
   m_icon->setPixmap(*img);

   QVBoxLayout *vbox = new QVBoxLayout;
   QHBoxLayout *hbox = new QHBoxLayout;
   hbox->addStretch(1);
   hbox->addWidget(m_icon);
   hbox->addStretch(1);

   QHBoxLayout *hbox1 = new QHBoxLayout;
   hbox1->addStretch(1);
   hbox1->addWidget(m_text);
   hbox1->addStretch(1);

   vbox->addLayout(hbox);
   vbox->addLayout(hbox1);
   vbox->addStretch(1);
   setLayout(vbox);
}

MyTab::~MyTab()
{

}

