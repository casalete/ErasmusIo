#include "newteacher.h"
#include "ui_newteacher.h"

NewTeacher::NewTeacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewTeacher)
{
    ui->setupUi(this);
}

NewTeacher::~NewTeacher()
{
    delete ui;
}
