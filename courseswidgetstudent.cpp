#include "courseswidgetstudent.h"
#include "ui_courseswidgetstudent.h"
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
CoursesWidgetStudent::CoursesWidgetStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoursesWidgetStudent)
{
    ui->setupUi(this);


    QSqlDatabase db_courses;
    db_courses = QSqlDatabase::addDatabase("QPSQL","studentCourses");
    db_courses.setHostName("localhost");  // host
    db_courses.setDatabaseName("erasmusio");
    db_courses.setUserName("erasmusio");
    db_courses.setPassword("erasmusio");
    db_courses.open();


    QSqlQueryModel* modal = new QSqlQueryModel();


    QSqlQuery* qry = new QSqlQuery(db_courses);




//name, teacher_name, no_credits, optionality, no_hours_w
     qry->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours_w FROM course");
     qry->exec();
     modal->setQuery(*qry);
     ui->tableView->setModel(modal);

}

CoursesWidgetStudent::~CoursesWidgetStudent()
{
    delete ui;
}

void CoursesWidgetStudent::on_back_clicked()
{
    hide();
}

