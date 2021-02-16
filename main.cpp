#include "MainWindow.h"
#include "Commander.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    Commander::instance();
    Commander::instance()->get_rsa()->set_data_manager(Commander::instance()->get_dt_mg());
    Commander::instance()->get_mw()->show();

    return a.exec();
}
