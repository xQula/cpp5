#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QTimer>
#include "myTime.h"

class StopWatch : public QObject{
    Q_OBJECT
public:
    StopWatch(QObject *parent = nullptr);
    QString out_basic_time() const;
    QString out_time_cycle() const;
    void update_time();
    void reset_basic_time();
    void reset_cycle_time();
    void reset_count_cycle_();
    void update_count_cycle();
    void start_timer();
    void stop_timer();
    int get_count_cycle() const;
private:
    int count_cycle_;
    MyTime *time_;
    MyTime *time_cycle_;
    QTimer *timer_;
signals:
    void sg_update_time();
private slots:
};

#endif // STOPWATCH_H
