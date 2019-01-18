#include "courseswidgetstudent.h"
#include "ui_courseswidgetstudent.h"

CoursesWidgetStudent::CoursesWidgetStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoursesWidgetStudent)
{
    ui->setupUi(this);

}

CoursesWidgetStudent::~CoursesWidgetStudent()
{
    delete ui;
}
