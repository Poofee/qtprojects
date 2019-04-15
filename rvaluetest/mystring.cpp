#include "mystring.h"

MyString::MyString()
    :_data(nullptr)
    ,_length(0)
{
    qDebug()<<Q_FUNC_INFO;
}

MyString::MyString(const char *p)
{
    qDebug()<<Q_FUNC_INFO<<p;
    _length = strlen(p);
    init_data(p);
}

MyString::MyString(const MyString &str)
{
    qDebug()<<Q_FUNC_INFO<<str._data;
    _length = str._length;
    init_data(str._data);
}

MyString::MyString(MyString &&str)
{
    qDebug()<<"Move constructor is called here!";
    _length = str._length;
    _data = str._data;
    str._length = 0;
    str._data = nullptr;/** 防止调用析构函数的时候释放空间 **/
}

MyString::~MyString()
{
    if(_data != nullptr){
        qDebug()<<Q_FUNC_INFO;
        free(_data);
    }
}

MyString &MyString::operator=(const MyString &str)
{
    qDebug()<<Q_FUNC_INFO;
    if(this != &str){
        _length = str._length;
        init_data(str._data);
    }
    return *this;
}

MyString &MyString::operator=(MyString &&str)
{
    qDebug()<<"Move assignment is called here!";
    if(this != &str){
        _length = str._length;
        _data = str._data;
        str._length = 0;
        str._data = nullptr;
    }
    return *this;
}


