#include "newstudent.h"
#include "ui_newstudent.h"

NewStudent::NewStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewStudent)
{
    ui->setupUi(this);

    ui->comboBox_semester->addItem("Semester 1");
    ui->comboBox_semester->addItem("Semester 2");
    ui->comboBox_semester->addItem("Whole year");

}

NewStudent::~NewStudent()
{
    delete ui;
}
