#ifndef MYTIME_H
#define MYTIME_H
#include <QObject>

class MyTime : public QObject{
    Q_OBJECT
private:
    int hours_;
    int minuts_;
    int seconds_;
    int count_;
public:
    MyTime(QObject *parent = nullptr);
    virtual ~MyTime() = default;
    void reset();
    QString out() const;
    MyTime &operator++ ();
signals:
    void sg_update_time();
};

#endif // MYTIME_H
