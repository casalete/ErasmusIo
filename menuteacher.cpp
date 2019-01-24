#include "menuteacher.h"
#include "ui_menuteacher.h"

#include <QLineEdit>
#include "loginteacher.h"
#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include "mainwindow.h"
#include "QString"

MenuTeacher::MenuTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuTeacher)
{
    ui->setupUi(this);
  setWindowTitle("Menu Teacher");

}

MenuTeacher::~MenuTeacher()
{
    delete ui;
}

void MenuTeacher::on_coursesButton_clicked()
{
   // hide();
    widget = new Widget();
    widget->show();

}

void MenuTeacher::on_detailsButton_clicked()
{
   // hide();
    details = new Details();
    details->init(teacher_id);
    details->show();

}

void MenuTeacher::doQuery(int login_id){
    teacher_id = login_id;
    QSqlDatabase db_menuteacher;
    db_menuteacher = QSqlDatabase::database();
    QSqlQuery query(db_menuteacher);
    //QString id_string = QString::number(student_id);

    //query.prepare("SELECT first_name, last_name, email, password FROM student where id ='" + id_string + "'");

    QString id_string = QString::number(teacher_id);
    QString queryString = "SELECT first_name, last_name, email,course_name, password FROM teacher where id ='" + id_string + "'";
     query.prepare(queryString);

        query.exec();

        while(query.next()){
               QString  firstname = query.value(0).toString();
               ui->lineEdit_firstName->setText(firstname);

               QString lastname = query.value(1).toString();
                ui->lineEdit_lastName->setText(lastname);

               QString email = query.value(2).toString();
                ui->lineEdit_email->setText(email);

               QString coursename = query.value(3).toString();
               ui->lineEdit_courseName->setText(coursename);

               QString password = query.value(4).toString();
               ui->lineEdit_password->setText(password);
           }
}
