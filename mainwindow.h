#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "StopWatch.h"

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
    StopWatch *watch_;

signals:
    void sig_psh_cycle_tap();

private slots:
    void on_psh_startStop_toggled(bool checked);
    void on_psh_cycle_clicked();
    void sl_edit_pb_cycle();
    void on_psh_clear_clicked();
};
#endif // MAINWINDOW_H
