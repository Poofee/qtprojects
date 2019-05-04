#include "MyStringRValue.h"

MyStringRValue::MyStringRValue()
    :_data(nullptr)
    ,_length(0)
{
    qDebug()<<Q_FUNC_INFO;
}

MyStringRValue::MyStringRValue(const char *p)
{
    qDebug()<<Q_FUNC_INFO<<p;
    _length = strlen(p);
    init_data(p);
}


MyStringRValue::MyStringRValue(MyStringRValue &&str)
{
    qDebug()<<"Move constructor is called here!";
    _length = str._length;
    _data = str._data;
    str._length = 0;
    str._data = nullptr;/** 防止调用析构函数的时候释放空间 **/
}

MyStringRValue::~MyStringRValue()
{
    if(_data != nullptr){
        qDebug()<<Q_FUNC_INFO;
        free(_data);
    }
}

MyStringRValue &MyStringRValue::operator=(const MyStringRValue &str)
{
    qDebug()<<Q_FUNC_INFO;
    if(this != &str){
        _length = str._length;
        init_data(str._data);
    }
    return *this;
}

MyStringRValue &MyStringRValue::operator=(MyStringRValue &&str)
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


