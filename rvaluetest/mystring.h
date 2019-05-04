#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
#include <QDebug>

/*!
 \brief 可以对比一下注视掉右值引用的函数前后的输出，明显调用次数少了。

*/
class MyString
{
public:
    MyString();
    MyString(const char* p);
    MyString(const MyString& str);
    ~MyString();

    MyString& operator=(const MyString& str);

private:
    void init_data(const char* s){
        _data = new char[_length + 1];
        memcpy(_data, s, _length);
        _data[_length] = '\0';
    }
private:
    char* _data;
    size_t _length;
};

#endif // MYSTRING_H
