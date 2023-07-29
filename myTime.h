#ifndef MYTIME_H
#define MYTIME_H
#include <QObject>

class MyTime{
private:
    int hours_;
    int minuts_;
    int seconds_;
public:
    MyTime();
    virtual ~MyTime() = default;
    int get_hours() const;
    int get_minuts() const;
    int get_seconds() const;
    void reset();
    QString out() const;
    MyTime &operator++ ();
};

#endif // MYTIME_H
