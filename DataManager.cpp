#include "DataManager.h"

DataManager::DataManager() : str_data {""} {}

void DataManager::fill_block_numbers(){
    for(u_ll i{0}; i < str_data.size(); ++i){
        block_numbers[i] = i;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(block_numbers.begin(), block_numbers.end(), std::default_random_engine(seed)); //перемешиваем числа в векторе, что бы не было 1 2 3 . . .
}

void DataManager::set_str_data(QString str){
    str_data = "";
    str_data.shrink_to_fit();
    str_data = str;

    block_numbers.clear();
    block_numbers.resize(str_data.size());

    encr_block_numbers.clear();
    encr_block_numbers.resize(str_data.size());

    decr_block_numbers.clear();
    decr_block_numbers.resize(str_data.size());

    fill_block_numbers();

    decr_numb_for_get_ch.clear();
    fill_decr_numb_for_get_ch();
}

DataManager::~DataManager(){}

void DataManager::fill_decr_numb_for_get_ch(){
    char tmp_ch;
    for(int i{0}; i < block_numbers.size(); ++i){
        tmp_ch = str_data.toStdString().c_str()[i];
        decr_numb_for_get_ch[block_numbers[i]] = tmp_ch;
    }
}

std::map <u_ll, char> DataManager::get_decr_numb_for_get_ch(){
    return decr_numb_for_get_ch;
}
