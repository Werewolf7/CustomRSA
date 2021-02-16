#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <map>
#include <QString>
#include <QDebug>

using u_ll = unsigned long long;

class DataManager{
private:
    //После того как поставили в соответствие всем символам - цифры, храним их для проверки расшифрования
    std::map <u_ll, char> decr_numb_for_get_ch;
public:

    //Исходная строка
    QString str_data;

    //Числа для каждого блока
    std::vector<u_ll> block_numbers;

    //Числа зашифрованных блоков
    std::vector<u_ll> encr_block_numbers;

    //Числа расшифрованных блоков
    std::vector<u_ll> decr_block_numbers;

    //Конструктор
    DataManager();

    //Заполнение блоков числами
    void fill_block_numbers();

    //Устанавливаем текущую считанную строку
    void set_str_data(QString str);

    //Деструктор
    ~DataManager();

    //Заполнение поля decr_numb_for_get_ch
    void fill_decr_numb_for_get_ch();

    //Геттерр карты(отображение из числа в символ)
    std::map <u_ll, char> get_decr_numb_for_get_ch();
};

#endif // DATAMANAGER_H
