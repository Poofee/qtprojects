#include "mainwindow.h"
#include <QApplication>

#include "mystring.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /** 右值引用测试 需要C++11支持 **/
    MyString str;
    str = MyString("Hello");
    std::vector<MyString> vec;
    vec.push_back(MyString("World"));

    // result
//    18:59:32: Starting D:\qtprojects\build-rvaluetest-msvc-Debug\debug\rvaluetest...
//    __cdecl MyString::MyString(void)
//    __cdecl MyString::MyString(const char *) Hello
//    class MyString &__cdecl MyString::operator =(const class MyString &)
//    __cdecl MyString::~MyString(void)
//    __cdecl MyString::MyString(const char *) World
//    __cdecl MyString::MyString(const class MyString &) World
//    __cdecl MyString::~MyString(void)
//    19:08:52: 程序异常结束。
//    19:08:52: The process was ended forcefully.
//    __cdecl MyString::~MyString(void)
//    __cdecl MyString::~MyString(void)
//    19:08:52: D:/qtprojects/build-rvaluetest-msvc-Debug/debug/rvaluetest crashed.

//    19:08:53: Starting D:\qtprojects\build-rvaluetest-msvc-Debug\debug\rvaluetest...
//    __cdecl MyString::MyString(void)
//    __cdecl MyString::MyString(const char *) Hello
//    Move assignment is called here!
//    __cdecl MyString::MyString(const char *) World
//    Move constructor is called here!
//    __cdecl MyString::~MyString(void)
//    __cdecl MyString::~MyString(void)
    return a.exec();
}
