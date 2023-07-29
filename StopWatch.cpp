#include "StopWatch.h"

StopWatch::StopWatch(QObject *parent):
    QObject(parent),
    time_(new MyTime(this)),
    time_cycle_(new MyTime(this)),
    timer_(new QTimer(this)),
    count_cycle_(0)
{
    timer_->setInterval(100);
    connect(timer_, &QTimer::timeout, this, [this]{++*time_;});
    connect(timer_, &QTimer::timeout, this, [this]{++*time_cycle_;});
    connect(time_, &MyTime::sg_update_time, this, [this]{emit this->sg_update_time();});
}

QString StopWatch::out_basic_time() const
{
    return time_->out();
}

QString StopWatch::out_time_cycle() const
{
    return time_cycle_->out();
}

void StopWatch::reset_basic_time()
{
    time_->reset();
}

void StopWatch::reset_cycle_time()
{
    time_cycle_->reset();
}

void StopWatch::reset_count_cycle_()
{
    count_cycle_ = 0;
}

void StopWatch::update_count_cycle()
{
    ++count_cycle_;
}

void StopWatch::start_timer()
{
    timer_->start();
}

void StopWatch::stop_timer()
{
    timer_->stop();
}

int StopWatch::get_count_cycle() const
{
    return count_cycle_;
}


