#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

template <class ForwardIterator>
ForwardIterator Myunique (ForwardIterator first, ForwardIterator last)
{
    if (first==last) return last;

    ForwardIterator result = first;
    while (++first < last)
    {
        if(*result == *first){
            /** 由于在这里已经到达last了，导致下一次加的时候就超过
             * last了，报错 **/
            while (++first != last) {
//                qDebug()<<*first;
                if(*result != *first){
                    *result = *first;
                    break;
                }
            }
        }else{
            *(++result)=*first;
//            qDebug()<<*first;
        }
        /** 最后一个数是不重复的 **/
//        if (first==last-1){
//            break;
//        }
        /** 最后几个数是重复的 **/
        if (first==last){
            return result;
        }
    }
    return ++result;
}
template <class ForwardIterator>
ForwardIterator Cppunique (ForwardIterator first, ForwardIterator last)
{
    if (first==last) return last;

    ForwardIterator result = first;
    while (++first != last)
    {
        if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
            *(++result)=*first;
    }
    return ++result;
}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    vector<int> a ={100,100,100,100,1,2,3,4,5,5,101,102};
    vector<int>::iterator it_1 = a.begin();
    vector<int>::iterator it_2 = a.end();
    vector<int>::iterator new_end;

    sort(it_1,it_2);
    new_end = Myunique(it_1,it_2);
    a.erase(new_end,it_2);
    qDebug()<<"a : ";
    for(int i = 0 ; i < a.size(); i++)
        qDebug()<<a[i];

    return app.exec();
}
