#include "view.h"

#include <QToolButton>
#include <QToolBar>
#include <QAction>
#include <QDebug>

View::View(QWidget *parent)
    : QWidget(parent)
{
    init();
}

View::~View()
{

}

void View::init()
{
    toolBar = new QToolBar(this);
    toolBar->setIconSize(QSize(24,24));
    toolBar->setObjectName("ToolBar");

    zoom = new QAction(QIcon(":/res/zoombox.png"),"Zoom",this);
    zoom->setCheckable(true);
    connect(zoom,&QAction::triggered,[this]()
    {
        qDebug()<<"Zoom";
        this->zoom->setChecked(zoom->isChecked());
    });
    zoomextents = new QAction(QIcon(":/res/zoomextents.png"),"ZoomExtents",this);
    zoomextents->setCheckable(true);
    connect(zoomextents,&QAction::triggered,[this]()
    {
        qDebug()<<"Zoom";
        this->zoomextents->setChecked(zoomextents->isChecked());
    });
    zoomin = new QAction(QIcon(":/res/zoomin.png"),"ZoomIn",this);
    zoomin->setCheckable(true);
    connect(zoomin,&QAction::triggered,[this]()
    {
        qDebug()<<"Zoom";
        this->zoomin->setChecked(zoomin->isChecked());
    });
    zoomout = new QAction(QIcon(":/res/zoomout.png"),"ZoomOut",this);
    zoomout->setCheckable(true);
    connect(zoomout,&QAction::triggered,[this]()
    {
        qDebug()<<"Zoom";
        this->zoomout->setChecked(zoomout->isChecked());
    });
    zoomselected = new QAction(QIcon(":/res/zoomselected.png"),"ZoomSelected",this);
    zoomselected->setCheckable(true);
    connect(zoomselected,&QAction::triggered,[this]()
    {
        qDebug()<<"Zoom";
        this->zoomselected->setChecked(zoomselected->isChecked());
    });

    toolBar->addAction(zoom);
    toolBar->addAction(zoomextents);
    toolBar->addSeparator();
    toolBar->addAction(zoomin);
    toolBar->addAction(zoomout);
    toolBar->addAction(zoomselected);
}
