#include "widget.h"
#include <QApplication>
#include <QString>
#include <QVector>

#include <stdio.h>

class CPoint{
public:
    double x;
    double y;
};

/*!
 \brief 将几何数据导出为DXF文件

 \param fileName
 \return bool
*/
bool writeDXF(char fileName[]){
    int i,j,k;
    double x0,y0,x1,y1,R,dt;
    double extmaxx,extminx,extmaxy,extminy;
    bool laze[256];
    int nlaze;
    char lay[256];
    //    CComplex c,p,s;
    FILE *fp;

    if ((fp=fopen(fileName,"wt")) == nullptr)
        return false;

    /** 计算边界 **/
    QVector<CPoint> nodeList;
    if (nodeList.size() < 2){
        extmaxx = 1;
        extmaxy = 1;
        extminx = 0;
        extminy = 0;
    }
    else{
        extminx = nodeList[0].x;
        extminy = nodeList[0].y;
        extmaxx = extminx;
        extmaxy = extminy;
        for(i=1;i<nodeList.size();i++)
        {
            if(nodeList[i].x<extminx) extminx=nodeList[i].x;
            if(nodeList[i].x>extmaxx) extmaxx=nodeList[i].x;
            if(nodeList[i].y<extminy) extminy=nodeList[i].y;
            if(nodeList[i].y>extmaxy) extmaxy=nodeList[i].y;
        }

    }

    return true;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
