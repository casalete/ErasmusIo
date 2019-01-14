#include "loginstudent.h"
#include "ui_loginstudent.h"

LogInStudent::LogInStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInStudent)
{
    ui->setupUi(this);
}

LogInStudent::~LogInStudent()
{
    delete ui;
}
