#include "newstudent.h"
#include "ui_newstudent.h"

NewStudent::NewStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewStudent)
{
    ui->setupUi(this);
}

NewStudent::~NewStudent()
{
    delete ui;
}
