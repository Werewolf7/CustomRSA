#include "Commander.h"

Commander* Commander::cmd = nullptr;

Commander::Commander(){
    dt_mg = new DataManager;
    rsa = new RSA;
    mw = new MainWindow;
}

Commander::~Commander(){
    delete dt_mg;
    dt_mg = nullptr;
    delete rsa;
    rsa = nullptr;
    delete mw;
    mw = nullptr;
}

Commander* Commander::instance(){
    if(cmd != nullptr){
        return cmd;
    }
    cmd = new Commander;
    return cmd;
}

void Commander::delete_commander(){
    delete cmd;
    cmd = nullptr;
}

DataManager* Commander::get_dt_mg(){
    return dt_mg;
}

RSA* Commander::get_rsa(){
    return rsa;
}

MainWindow* Commander::get_mw(){
    return mw;
}







