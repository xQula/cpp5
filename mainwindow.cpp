#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      timer_(new QTimer(this)),
      my_time_(new MyTime())
{
    time_num_ = 0;
    ui->setupUi(this);
    ui->psh_startStop->setText("Start");
    ui->psh_startStop->setCheckable(true);
    ui->psh_clear->setText("Clear");
    ui->psh_cycle->setText("Cycle");
    ui->psh_reset_pt_time_Cycle->setText("Clear Text");
    ui->pt_timeCycle->setReadOnly(true);
    timer_->setInterval(1000);
    timer_->start();
    connect(this, &MainWindow::sig_psh_cycle_tap, this, &MainWindow::sl_edit_pb_cycle);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete my_time_;
}

void MainWindow::sl_updateTime()
{
    ui->lb_time->setText(my_time_->out());
    ++*my_time_;
}

void MainWindow::on_psh_startStop_toggled(bool checked)
{
    if(checked){
        connect(timer_, &QTimer::timeout, this, &MainWindow::sl_updateTime);
        ui->psh_startStop->setText("Stop");
    }else{
        disconnect(timer_, &QTimer::timeout, this, &MainWindow::sl_updateTime);
        ui->psh_startStop->setText("Start");
    }
}


void MainWindow::on_psh_cycle_clicked()
{
    emit sig_psh_cycle_tap();
}

void MainWindow::sl_edit_pb_cycle()
{
    ui->pt_timeCycle->appendPlainText(my_time_->out());
}



void MainWindow::on_psh_clear_clicked()
{
    my_time_->reset();
    ui->lb_time->setText(my_time_->out());
}


void MainWindow::on_psh_reset_pt_time_Cycle_clicked()
{
    ui->pt_timeCycle->clear();
}

