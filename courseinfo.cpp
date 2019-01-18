#include "courseinfo.h"
#include "ui_courseinfo.h"

CourseINFO::CourseINFO(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseINFO)
{
    ui->setupUi(this);
}

CourseINFO::~CourseINFO()
{
    delete ui;
}
