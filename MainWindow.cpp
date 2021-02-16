#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);

    connect(ui->read_data_button, SIGNAL(clicked()), this, SLOT(on_read_data_button()));

    this->setWindowTitle("RSA by Sedov, Dorofeev, Lezin");
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_read_data_button(){
    algorithm_work();

    set_res();
}

void MainWindow::set_res(){
    QString qstr{""};
    for(auto it = Commander::instance()->get_rsa()->get_data_manager()->block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->block_numbers.end(); ++it){
        qstr += QString::number(*it) + " ";
    }

    QString qstr_encr{""};
    for(auto it = Commander::instance()->get_rsa()->get_data_manager()->encr_block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->encr_block_numbers.end(); ++it){
        qstr_encr += QString::number(*it) + " ";
    }

    QString qstr_decr{""};
    for(auto it = Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.end(); ++it){
        qstr_decr += QString::number(*it) + " ";
    }

    QString decr_str{""};
    for(auto it = Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.end(); ++it){
        decr_str += Commander::instance()->get_dt_mg()->get_decr_numb_for_get_ch()[*it];
    }

    if(qstr == qstr_decr){
        ui->block_nmb_label->setText(qstr);
        ui->encr_label->setText(qstr_encr);
        ui->decr_label->setText(qstr_decr);
        ui->decr_str_label->setText(decr_str);
    }

    else{
        algorithm_work();
        QString qstr{""};
        for(auto it = Commander::instance()->get_rsa()->get_data_manager()->block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->block_numbers.end(); ++it){
            qstr += QString::number(*it) + " ";
        }

        QString qstr_encr{""};
        for(auto it = Commander::instance()->get_rsa()->get_data_manager()->encr_block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->encr_block_numbers.end(); ++it){
            qstr_encr += QString::number(*it) + " ";
        }

        QString qstr_decr{""};
        for(auto it = Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.end(); ++it){
            qstr_decr += QString::number(*it) + " ";
        }

        QString decr_str{""};
        for(auto it = Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.begin(); it != Commander::instance()->get_rsa()->get_data_manager()->decr_block_numbers.end(); ++it){
            decr_str += Commander::instance()->get_dt_mg()->get_decr_numb_for_get_ch()[*it];
        }
    }
}

void MainWindow::algorithm_work(){
    Commander::instance()->get_rsa()->initialization_rsa();

    QString tmp_str_data = ui->textEdit->toPlainText();

    Commander::instance()->get_dt_mg()->set_str_data(tmp_str_data);

    Commander::instance()->get_rsa()->encryption();
    Commander::instance()->get_rsa()->decryption();
}

