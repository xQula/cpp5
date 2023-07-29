#include "myTime.h"

MyTime::MyTime(QObject *parent):
    QObject(parent), hours_(0), minuts_(0), seconds_(0), count_(0)
{

}

void MyTime::reset()
{
    hours_ = 0;
    minuts_ = 0;
    seconds_ = 0;
}

QString MyTime::out() const
{
    return  QString::number(hours_) + ":" +
            QString::number(minuts_) + ":" +
            QString::number(seconds_);
}

MyTime &MyTime::operator++()
{
    ++count_;
    if(count_ == 10){
        count_ = 0;
        ++seconds_;
        if(seconds_ == 60){
            seconds_ = 0;
            ++minuts_;
        }
        if(minuts_ == 60){
            minuts_ = 0;
            ++hours_;
        }
       if(hours_ == 24 && minuts_ == 59 && seconds_ == 60){
            reset();
        }
        emit sg_update_time();
    }
    return *this;
}

