#include "menustudent.h"
#include "ui_menustudent.h"

#include <QLineEdit>
#include "loginstudent.h"
#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include "mainwindow.h"
#include "QString"

MenuStudent::MenuStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuStudent)
{
    ui->setupUi(this);
      setWindowTitle("Menu Student");

}



MenuStudent::~MenuStudent()
{
    delete ui;
}

void MenuStudent::on_coursesButton_clicked()
{
    widget = new CoursesWidgetStudent();
    widget->init(student_id);
    widget->show();
}

void MenuStudent::on_myCoursesBtn_clicked()
{
    mycourses = new MyCourses();
    mycourses->init(student_id);
    mycourses->show();
}

void MenuStudent::setValueFromSignal(int val){
    student_id = val;
}

void MenuStudent::doQuery(int val){
    student_id = val;
    QSqlDatabase db_menustudent;
    db_menustudent = QSqlDatabase::database();
    QSqlQuery query(db_menustudent);
    QString id_string = QString::number(student_id);
    QString queryString = "SELECT first_name, last_name, email, country, password, university_name, study_duration, semester FROM student where id ='" + id_string + "'";
    // query.prepare("SELECT first_name, last_name, email,country,study_duration, semester, university_name, password FROM student ");
    query.prepare(queryString);
    query.exec();

    while(query.next()){
           QString  firstname = query.value(0).toString();
           ui->lineEdit_firstName->setText(firstname);

           QString lastname = query.value(1).toString();
           ui->lineEdit_lastName->setText(lastname);

           QString email = query.value(2).toString();
           ui->lineEdit_email->setText(email);

           QString country = query.value(3).toString();
           ui->lineEdit_country->setText(country);

           QString password = query.value(4).toString();
           ui->lineEdit_password->setText(password);

           QString university_name = query.value(5).toString();
           ui->lineEdit_university->setText(university_name);

           QString duration = query.value(6).toString();
           ui->lineEdit_duration->setText(duration);

           QString semester = query.value(7).toString();
           ui->lineEdit_period->setText(semester);

       }
}

void MenuStudent::on_submitButton_clicked()
{
    QString firstname = ui->lineEdit_firstName->text();
    QString lastname = ui->lineEdit_lastName->text();
    QString email = ui->lineEdit_email->text();
    QString country = ui->lineEdit_country->text();
    QString password = ui->lineEdit_password->text();
    QString university_name = ui->lineEdit_university->text();
    QString duration = ui->lineEdit_duration->text();
    QString semester = ui->lineEdit_period->text();

    QString studentIdString = QString::number(student_id);
    QSqlDatabase db_student;
    db_student = QSqlDatabase::database("QPSQL");
    QSqlQuery query_student(db_student);
    query_student.prepare("UPDATE student SET first_name='"+firstname+"',last_name='"+lastname+"',email='"+email+"',country='"+country+"',password='"+password+"',study_duration='"+duration+"',semester ='"+semester+"',university_name ='"+university_name+"' WHERE id = '"+studentIdString+"'");
    if(query_student.exec()){
        QMessageBox::information(this,tr("SAVE"),tr("STUDENT EDITED"));
    }
    else{
        QMessageBox::critical(this,tr("error::"),tr("FAILED TO EDIT STUDENT"));
    }


}
