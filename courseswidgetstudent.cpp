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
    db_courses = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_course = new QSqlQuery(db_courses);
    query_course->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours FROM course");
    query_course->exec();
    modalTable->setQuery(*query_course);
    ui->tableView->setModel(modalTable);
    query_course->prepare("SELECT name from course");
    query_course->exec();
    ui->comboBox->setModel(modalTable);


    QSqlQueryModel* modalList = new QSqlQueryModel();
    QSqlQuery* query_student_courses = new QSqlQuery(db_courses);
    query_student_courses->prepare("SELECT name FROM course");
    query_student_courses->exec();
    modalList->setQuery(*query_student_courses);
    ui->listView->setModel(modalList);

}

CoursesWidgetStudent::~CoursesWidgetStudent()
{
    delete ui;
}

void CoursesWidgetStudent::on_back_clicked()
{
    hide();
}


void CoursesWidgetStudent::on_pushButton_clicked()
{
    QSqlDatabase db_course;
    db_course = QSqlDatabase::database("QPSQL");
    QSqlQuery query_courses = QSqlQuery(db_course);
   // query_courses.prepare("INSERT into student_course () ")

            //query.prepare("INSERT INTO student (first_name, last_name, email, country, study_duration, semester, university_name,  password)"
               //        "VALUES (?,?,?,?,?,?,?,?)");
}
