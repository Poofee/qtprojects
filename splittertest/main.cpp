#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ont::QFont(const QString & family, int pointSize = -1, int weight = -1, bool italic = false)
    //第一个参数是字体族，第二个是字体尺寸，第三个是加粗系数，第四个是斜体设置
    QFont font("ZYSong18030",12);//指定显示字体
    a.setFont(font);

    QSplitter *splitterMain;
    QTextEdit *textleft;
    QSplitter *splitterRight;
    QTextEdit *textUp;
    QTextEdit *textBottom;
    splitterMain=new QSplitter(Qt::Horizontal,0);                   //Horizontal:水平的
    textleft=new QTextEdit(QObject::tr("Left Widget"),splitterMain);
    textleft->setAlignment(Qt::AlignCenter);
    //右部分分割窗口
    splitterRight=new QSplitter(Qt::Vertical,splitterMain);        //Vertical：垂直的
    splitterRight->setOpaqueResize(false);                                    //Opaque：不透明的
    textUp =new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);
    textBottom=new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);
    splitterMain->setStretchFactor(0,1);                                      //Stretch Factor:拉伸系数
    splitterMain->setStretchFactor(1,2);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();

    return a.exec();
}
