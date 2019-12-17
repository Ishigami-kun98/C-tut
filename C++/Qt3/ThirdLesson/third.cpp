#include "third.h"
#include "ui_third.h"
#include <QString>

Third::Third(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Third)
{
    ui->setupUi(this);
}

Third::~Third()
{
    delete ui;
}

void Third::on_button_back_clicked(        )
{

}

void Third::on_button_next_clicked()
{

}

void Third::on_button_add_clicked()
{
    contact c;
    c.last_name = ui -> lineEdit_2 -> text().toStdString();
    c.firstname = ui -> lineEdit -> text().toStdString();
    this -> contact_list.push_back(c);
}

void Third:: updateUI(){
    contact tmp = this -> contact_list[this -> current_id];
    ui -> lineEdit_2 -> setText(tmp.last_name.c_str());
    ui -> lineEdit -> setText(tmp.firstname.c_str());
    ui -> label -> setText(QString:: number(this -> current_id) + "/" + QString:: number(this -> contact_list.size()));
}
