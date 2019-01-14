#include "loginteacher.h"
#include "ui_loginteacher.h"

LoginTeacher::LoginTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginTeacher)
{
    ui->setupUi(this);
}

LoginTeacher::~LoginTeacher()
{
    delete ui;
}

void LoginTeacher::on_loginButton_clicked()
{
    hide();
    menuteacher = new MenuTeacher();
    menuteacher->show();
}
