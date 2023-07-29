#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include "myTime.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer_;
    MyTime *my_time_;
    int time_num_;

signals:
    void sig_psh_cycle_tap();

private slots:
    void sl_updateTime();
    void on_psh_startStop_toggled(bool checked);
    void on_psh_cycle_clicked();
    void sl_edit_pb_cycle();
    void on_psh_clear_clicked();
    void on_psh_reset_pt_time_Cycle_clicked();
};
#endif // MAINWINDOW_H
