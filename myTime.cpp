#include "myTime.h"

MyTime::MyTime(): hours_(0), minuts_(0), seconds_(0)
{

}

int MyTime::get_hours() const
{
    return hours_;
}

int MyTime::get_minuts() const
{
    return minuts_;
}

int MyTime::get_seconds() const
{
    return seconds_;
}

void MyTime::reset()
{
    hours_ = 0;
    minuts_ = 0;
    seconds_ = 0;
}

QString MyTime::out() const
{
    return  QString::number(this->get_hours()) + ":" +
            QString::number(this->get_minuts()) + ":" +
            QString::number(this->get_seconds());
}

MyTime &MyTime::operator++()
{
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
    return *this;
}

