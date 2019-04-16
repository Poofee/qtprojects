#include "mainwindow.h"
#include <QApplication>

#include "mystring.h"
#include "mystringrvalue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MyString str;
    str = MyString("Hello");
    std::vector<MyString> vec;
    vec.push_back(MyString("World"));

    /** 右值引用测试 需要C++11支持 **/
    qDebug()<<"RValue output:----------------------------";
    MyStringRValue str1;
    str1 = MyStringRValue("Hello");
    std::vector<MyStringRValue> vec1;
    vec1.push_back(MyStringRValue("World"));
    return a.exec();
}
