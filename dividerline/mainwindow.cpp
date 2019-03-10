#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>

#include "welcomepageframe.h"
#include "welcomepagebutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vboxleft = new QVBoxLayout;
    QToolButton *button1 = new QToolButton(this);
    button1->setText("button1");
    QToolButton *button2 = new QToolButton(this);
    button2->setText("button2");
    QToolButton *button3 = new QToolButton(this);
    button3->setText("button3");
    vboxleft->addWidget(button1);
    vboxleft->addWidget(button2);
    vboxleft->addWidget(button3);

    QWidget *divider = new QWidget(this);
    divider->setMaximumWidth(1);
    divider->setMinimumWidth(1);
    divider->setAutoFillBackground(true);
    divider->setPalette(QPalette(Qt::darkBlue));

    QVBoxLayout *vboxright = new QVBoxLayout;
    vboxright->setContentsMargins(2,2,2,2);
    WelcomePageButton *button4 = new WelcomePageButton(this);
    button4->setText("button4");
    button4->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    WelcomePageButton *button5 = new WelcomePageButton(this);
    button5->setText("button5");
    button5->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    WelcomePageButton *button6 = new WelcomePageButton(this);
    button6->setText("button6");
    button6->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vboxright->addStretch(1);
    vboxright->addWidget(button4);
    vboxright->addWidget(button5);
    vboxright->addWidget(button6);

    vboxright->addStretch(1);
    vboxright->stretch(1);

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addLayout(vboxleft);
    hbox->addWidget(divider);
    hbox->addLayout(vboxright);

    setLayout(hbox);
}

MainWindow::~MainWindow()
{

}
