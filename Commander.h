#ifndef COMMANDER_H
#define COMMANDER_H

#include <QApplication>


#include "MainWindow.h"
#include "ui_mainwindow.h"

#include "DataManager.h"
#include "RSA.h"


class MainWindow;

class Commander{
private:
    //Указатель на датаменеджер
    DataManager* dt_mg;

    //Указатель на RSA
    RSA* rsa;

    //Указатель на главное окно
    MainWindow* mw;

    //Статик коммандер
    static Commander* cmd;
public:

    //Конструктор
    Commander();

    //Деструктор
    ~Commander();

    //Сооздание и инициализация статик коммандера
    static Commander* instance();

    //Очистка указателя
    void delete_commander();

    //Геттер датаменеджера
    DataManager* get_dt_mg();

    //Геттер rsa
    RSA* get_rsa();

    //Геттер окна
    MainWindow* get_mw();
};

#endif // COMMANDER_H
