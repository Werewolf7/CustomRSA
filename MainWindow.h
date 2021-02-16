#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <iostream>
#include <QTextCodec>

#include "DataManager.h"
#include "Commander.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
public slots:
    void on_read_data_button();
    void set_res();
    void algorithm_work();
};
#endif // MAINWINDOW_H
