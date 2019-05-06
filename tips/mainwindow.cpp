#include "mainwindow.h"
#include "qcalltip.h"
#include <QLabel>
#include <QPainterPath>
#include <QDebug>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    QCallTip* tip = new QCallTip(this);
//    la = new QLabel(this);
//    la->setText("hello");
//    la->setGeometry(300,400,40,40);
    setMouseTracking(true);
    setGeometry(300,300,600,1000);

    inGeo = false;
    currentIndex = -1;

    selected = QColor(180,180,242);
    noSelected = QColor(200,200,200);
    toSelect = QColor(242,140,140);
    deSelect = QColor(140,242,140);

    QPolygonF air;
    air.append(QPointF(6,917));
    air.append((QPointF(459,917)));
    air.append((QPointF(459,8)));
    air.append(QPointF(6,8));
    air.append(QPointF(6,917));

    QPolygonF mover;
    mover.append(QPointF(16,495));
    mover.append(QPointF(50,495));
    mover.append(QPointF(50,423));
    mover.append(QPointF(16,423));
    mover.append(QPointF(16,495));

    QPolygonF pm;
    pm.append(QPointF(6,100));
    pm.append(QPointF(50,100));
    pm.append(QPointF(50,200));
    pm.append(QPointF(6,200));
    pm.append(QPointF(6,100));

    QPolygonF xiantie;
    xiantie.append(QPointF(6,634));
    xiantie.append(QPointF(180,634));
    xiantie.append(QPointF(180,294));
    xiantie.append(QPointF(27,294));
    xiantie.append(QPointF(27,315));
    xiantie.append(QPointF(20,315));
    xiantie.append(QPointF(20,379));
    xiantie.append(QPointF(17,379));
    xiantie.append(QPointF(17,402));
    xiantie.append(QPointF(51,402));
    xiantie.append(QPointF(51,315));
    xiantie.append(QPointF(167,315));
    xiantie.append(QPointF(167,437));
    xiantie.append(QPointF(167,469));
    xiantie.append(QPointF(167,619));
    xiantie.append(QPointF(51,619));
    xiantie.append(QPointF(51,502));
    xiantie.append(QPointF(6,502));
    xiantie.append(QPointF(6,634));

    QPolygonF upcoil;
    upcoil.append(QPointF(62,429));
    upcoil.append(QPointF(156,429));
    upcoil.append(QPointF(156,382));
    upcoil.append(QPointF(62,382));
    upcoil.append(QPointF(62,429));

    QPolygonF downcoil;
    downcoil.append(QPointF(62,611));
    downcoil.append(QPointF(154,611));
    downcoil.append(QPointF(154,476));
    downcoil.append(QPointF(62,476));
    downcoil.append(QPointF(62,611));

    QPolygonF pm1;
    pm1.append(QPointF(56,469));
    pm1.append(QPointF(167,469));
    pm1.append(QPointF(167,437));
    pm1.append(QPointF(56,437));
    pm1.append(QPointF(56,469));

//    QPainterPath geo;
    geo.addPolygon(air);
    geo.addPolygon(mover);
    geo.addPolygon(pm);
    geo.addPolygon(xiantie);
    geo.addPolygon(upcoil);
    geo.addPolygon(downcoil);
    geo.addPolygon(pm1);

    paths.append(geo);
//    paths.append(QPainterPath());
//    paths.last().addPolygon(air);
    paths.append(QPainterPath());
    paths.last().addPolygon(mover);
    paths.append(QPainterPath());
    paths.last().addPolygon(pm);
    paths.append(QPainterPath());
    paths.last().addPolygon(xiantie);
    paths.append(QPainterPath());
    paths.last().addPolygon(upcoil);
    paths.append(QPainterPath());
    paths.last().addPolygon(downcoil);
    paths.append(QPainterPath());
    paths.last().addPolygon(pm1);
    qDebug()<<paths.size();
//    //air
//    geo.moveTo(QPointF(6,917));
//    geo.lineTo((QPointF(459,917)));
//    geo.lineTo((QPointF(459,8)));
//    geo.lineTo(QPointF(6,8));
////    geo.lineTo(QPointF(6,917));

//    // mover;
//    geo.moveTo(QPointF(16,495));
//    geo.lineTo(QPointF(50,495));
//    geo.lineTo(QPointF(50,423));
//    geo.lineTo(QPointF(16,423));
////    geo.lineTo(QPointF(16,495));

//    // pm;
//    geo.moveTo(QPointF(6,100));
//    geo.lineTo(QPointF(50,100));
//    geo.lineTo(QPointF(50,200));
//    geo.lineTo(QPointF(6,200));
////    geo.lineTo(QPointF(6,100));

//    // xiantie;
//    geo.moveTo(QPointF(6,634));
//    geo.lineTo(QPointF(180,634));
//    geo.lineTo(QPointF(180,294));
//    geo.lineTo(QPointF(27,294));
//    geo.lineTo(QPointF(27,315));
//    geo.lineTo(QPointF(20,315));
//    geo.lineTo(QPointF(20,379));
//    geo.lineTo(QPointF(17,379));
//    geo.lineTo(QPointF(17,402));
//    geo.lineTo(QPointF(51,402));
//    geo.lineTo(QPointF(51,315));
//    geo.lineTo(QPointF(167,315));
//    geo.lineTo(QPointF(167,437));
//    geo.lineTo(QPointF(167,469));
//    geo.lineTo(QPointF(167,619));
//    geo.lineTo(QPointF(51,619));
//    geo.lineTo(QPointF(51,502));
//    geo.lineTo(QPointF(6,502));
////    geo.lineTo(QPointF(6,634));

//    // upcoil;
//    geo.moveTo(QPointF(62,429));
//    geo.lineTo(QPointF(156,429));
//    geo.lineTo(QPointF(156,382));
//    geo.lineTo(QPointF(62,382));
////    geo.lineTo(QPointF(62,429));

//    // downcoil;
//    geo.moveTo(QPointF(62,611));
//    geo.lineTo(QPointF(154,611));
//    geo.lineTo(QPointF(154,476));
//    geo.lineTo(QPointF(62,476));
////    geo.lineTo(QPointF(62,611));

//    // pm1;
//    geo.moveTo(QPointF(56,469));
//    geo.lineTo(QPointF(167,469));
//    geo.lineTo(QPointF(167,437));
//    geo.lineTo(QPointF(56,437));
////    geo.lineTo(QPointF(56,469));

}

MainWindow::~MainWindow()
{
    if(la)
        delete la;
    la = nullptr;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    //    la->setGeometry(e->x(),e->y(),100,100);
//    inGeo = geo.contains(QPoint(e->x(),e->y()));
    update();
//    qDebug()<<geo.contains(QPoint(e->x(),e->y()));
    for(int i = 0; i < paths.size();++i){
        if(paths.at(i).contains(QPoint(e->x(),e->y()))){
            currentIndex = i;
            qDebug()<<currentIndex;
            return;
        }
    }
    currentIndex = -1;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
//    QLinearGradient myGradient;
//    QPen myPen;
//    QPolygonF myPolygon;
//    myPolygon.append(QPointF(50,50));
//    myPolygon.append(QPointF(100,50));
//    myPolygon.append(QPointF(100,100));
//    myPolygon.append(QPointF(50,100));

//    QPolygonF myPolygonout;
//    myPolygonout.append(QPointF(0,0));
//    myPolygonout.append(QPointF(150,0));
//    myPolygonout.append(QPointF(150,150));
//    myPolygonout.append(QPointF(0,150));

//    QPainterPath myPath;
//    myPath.addPolygon(myPolygon);
//    myPath.addPolygon(myPolygonout);

//    QPainter painter(this);
//    painter.setBrush(QColor(Qt::red));
//    painter.setPen(QColor(Qt::red));
//    painter.drawPath(myPath);

//    QPainterPath dataPath;
////    myPath.setFillRule(Qt::OddEvenFill);
////    dataPath.moveTo(QPoint(200,200));
//    dataPath.addEllipse(200,200,200,200);
//    dataPath.addEllipse(275,275,50,50);
//    dataPath.addEllipse(250,250,30,30);

////    p.setPen(QPen(palette().shadow().color(), m_outlinePenWidth));
//    painter.setBrush(Qt::blue);
//    painter.drawPath(dataPath);
    QPainter painter(this);
    painter.setBrush(noSelected);
    painter.setPen(Qt::black);
    for(int i = 0;i < paths.size();++i){
        painter.drawPath(paths.at(i));
    }

    if(currentIndex >= 0){
        painter.setBrush(QColor(180,180,242));
        painter.setPen((Qt::black));
//        geo.setFillRule(Qt::OddEvenFill);
        painter.drawPath(paths.at(currentIndex));
    }

}
