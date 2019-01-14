#include "loginteacher.h"
#include "ui_loginteacher.h"

LogInTeacher::LogInTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInTeacher)
{
    ui->setupUi(this);
}

LogInTeacher::~LogInTeacher()
{
    delete ui;
}
