#ifndef RSA_H
#define RSA_H

#include <random>
#include <map>
#include <cmath>
#include <QDebug>

#include "DataManager.h"

using u_ll = unsigned long long;

class RSA{
private:
    //Указатель на датаменеджер
    DataManager* dt_mg;
    //Храним p,q,n,d,e
    std::map <char, u_ll> m_numbers_for_alg;
public:
    //Конструктор
    RSA();
    //Инициализация rsa
    void initialization_rsa();
    //Проверка на взаимную простоту
    bool is_coprime(u_ll a, u_ll b);
    //Алгоритм евклида(нод)
    u_ll gcd(u_ll a, u_ll b);
    //Получение рандомного числа [left_boundary; right_boundary]
    u_ll get_random_nmb(u_ll&& left_boundary, u_ll&& right_boundary);
    //Получение d
    u_ll get_d();
    //Получение e
    u_ll get_e();
    //Шифрование
    void encryption();
    //Установка указателя на датаменеджер
    void set_data_manager(DataManager* dt_mg);
    //Дешифровка
    void decryption();
    //Деструктор
    ~RSA();
    //Геттер датаменеджера
    DataManager* get_data_manager();
    //Очистка указателя на датаменджер
    void delete_data_manager();
    //Быстрое возведение в степень по модулю a^b mod n
    u_ll binpow(u_ll a, u_ll b, u_ll mod);
    //Является ли число простым
    bool isprime(int number);
};

#endif // RSA_H
