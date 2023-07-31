#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , watch_(new StopWatch(this))

{
    ui->setupUi(this);
    ui->psh_startStop->setText("Start");
    ui->psh_startStop->setCheckable(true);
    ui->psh_clear->setText("Clear");
    ui->psh_cycle->setText("Cycle");
    ui->pt_timeCycle->setReadOnly(true);
    ui->psh_cycle->setEnabled(false);
    connect(this, &MainWindow::sig_psh_cycle_tap, this, &MainWindow::sl_edit_pb_cycle);
    connect(watch_, &StopWatch::sg_update_time, this, [this]{ui->lb_time->setText(watch_->out_basic_time());});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_psh_startStop_toggled(bool checked)
{
    if(checked){
        watch_->start_timer();
        ui->psh_startStop->setText("Stop");
        ui->psh_cycle->setEnabled(true);
    }else{
        watch_->stop_timer();
        ui->psh_startStop->setText("Start");
        ui->psh_cycle->setEnabled(false);
    }
}


void MainWindow::on_psh_cycle_clicked()
{
    watch_->update_count_cycle();
    emit sig_psh_cycle_tap();
}

void MainWindow::sl_edit_pb_cycle()
{
    ui->pt_timeCycle->appendPlainText("Круг " + QString::number(watch_->get_count_cycle()) + " : " +  watch_->out_time_cycle());
    watch_->reset_cycle_time();
}



void MainWindow::on_psh_clear_clicked()
{
    watch_->reset_basic_time();
    watch_->reset_cycle_time();
    watch_->reset_count_cycle_();
    ui->lb_time->setText(watch_->out_basic_time());
    ui->pt_timeCycle->clear();
}

