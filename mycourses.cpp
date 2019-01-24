#include "mycourses.h"
#include "ui_mycourses.h"

MyCourses::MyCourses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyCourses)
{
    ui->setupUi(this);
}

MyCourses::~MyCourses()
{
    delete ui;
}
