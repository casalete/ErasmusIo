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
    QStringList labels;
    setWindowTitle("Courses");

    QSqlDatabase db_courses;
      db_courses = QSqlDatabase::database("QPSQL");
      QSqlQueryModel* modalTable = new QSqlQueryModel();
      QSqlQuery* query_course = new QSqlQuery(db_courses);
      query_course->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours FROM course");
      query_course->exec();
      modalTable->setQuery(*query_course);
      ui->tableView->setModel(modalTable);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addCourse_clicked()
{
    int res, nrHours,nrCreditPoints;
    QString courseName, teacherName, optionality;

    CourseDialog cd(this);
    cd.setWindowTitle("Add Course");
    res = cd.exec();
    if (res == QDialog::Rejected)
        return;

    courseName = cd.course();
    teacherName = cd.teacher();
    nrHours = cd.nrH();
    nrCreditPoints = cd.nrCP();
    optionality = cd.optionality();

//    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
//    counter = ui->tableWidget->rowCount() - 1;
//    ui->tableWidget->setItem(counter, COURSE, new QTableWidgetItem(courseName));
//    ui->tableWidget->setItem(counter, TEACHER, new QTableWidgetItem(teacherName));
//    ui->tableWidget->setItem(counter, NROFHOURS, new QTableWidgetItem(QString::number(nrHours)));
//    ui->tableWidget->setItem(counter, NROFCREDITPOINTS, new QTableWidgetItem(QString::number(nrCreditPoints)));
//    ui->tableWidget->setItem(counter, OPTIONALITY, new QTableWidgetItem(optionality));

    QSqlDatabase db_course;
    db_course = QSqlDatabase::database("QPSQL");
    QSqlQuery query_teacher_id(db_course);

    QString queryString = "SELECT id from teacher where last_name ='" + teacherName + "'";
    query_teacher_id.prepare(queryString);
    query_teacher_id.exec();
    int teacherID;
    while(query_teacher_id.next())
           {
            teacherID = query_teacher_id.value(0).toInt();
           }

    //query.prepare("SELECT first_name, last_name, email, password FROM student where id ='" + id_string + "'");
     QSqlQuery query_add_course(db_course);
     query_add_course.prepare("INSERT into course (name, teacher_name, no_credits, optionality, no_hours, id_teacher)"
             "VALUES(?,?,?,?,?,?)");
     query_add_course.addBindValue(courseName);
     query_add_course.addBindValue(teacherName);
     query_add_course.addBindValue(nrCreditPoints);
     query_add_course.addBindValue(optionality);
     query_add_course.addBindValue(nrHours);
     query_add_course.addBindValue(teacherID);

     query_add_course.exec();

}

///RESET
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

void Widget::on_back_clicked()
{
    hide();
}
