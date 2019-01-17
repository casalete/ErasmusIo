#include "createstudent.h"
#include "ui_createstudent.h"

CreateStudent::CreateStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateStudent)
{
    ui->setupUi(this);
}

CreateStudent::~CreateStudent()
{
    delete ui;
}
