#include "widget.h"
#include "ui_widget.h"
#include "coursedialog.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Courses");

    QSqlDatabase db_courses;
    db_courses = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_course = new QSqlQuery(db_courses);
    query_course->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours FROM course");
    query_course->exec();
    modalTable->setQuery(*query_course);
    ui->tableView->setModel(modalTable);
    //  initTableView();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addCourse_clicked()
{
    coursedialog = new CourseDialog;
    coursedialog->show();

}

void Widget::on_back_clicked()
{
    hide();
}


//void Widget::initTableView(){

//    QSqlDatabase db_courses;
//    db_courses = QSqlDatabase::database("QPSQL");
//    QSqlQueryModel* modalTable = new QSqlQueryModel();
//    QSqlQuery* query_course = new QSqlQuery(db_courses);
//    query_course->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours FROM course");
//    query_reset->exec();
//    modalList->setQuery(*query_reset);
//    ui->listView->setModel(modalList);

//}


void Widget::on_pushButton_clicked()
{
    ui->tableView->hide();
    QSqlDatabase db_courses;
    db_courses = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_course = new QSqlQuery(db_courses);
    query_course->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours FROM course");
    query_course->exec();
    modalTable->setQuery(*query_course);
    ui->tableView->setModel(modalTable);
    ui->tableView->show();
}
