#include "newteacher.h"
#include "ui_newteacher.h"
#include "mainwindow.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

NewTeacher::NewTeacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewTeacher)
{
    ui->setupUi(this);
}

NewTeacher::~NewTeacher()
{
    delete ui;
}

//TODO - ROLE
//QString role = "STUDENT";

//    QString role;
//    if(ui->studentRadioButton->isChecked())
//        role = "STUDENT";
//    else if (ui->teacherRadioButton->isChecked()){

//        if(email == "admin")
//            role = "ADMIN";
//        else
//            role = "TEACHER";
//    }
void NewTeacher::on_submitButton_clicked()
{
    //TODO - get values from ui

    QString form_first_name = ui->lineEdit_firstName->text();
    QString form_last_name = ui->lineEdit_lastName->text();
    QString form_email = ui->lineEdit_email->text();
    QString form_password = ui->lineEdit_password->text();
    QString form_course_name = ui->lineEdit->text();



    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("INSERT INTO teacher (first_name, last_name, email, password, course_name)"
               "VALUES (?,?,?,?,?)");

    query.addBindValue(form_first_name);
    query.addBindValue(form_last_name);
    query.addBindValue(form_email);
    query.addBindValue(form_password);
    query.addBindValue(form_course_name);








    query.exec();

//    ui->lineEdit_firstName->clear();
//    ui->lineEdit_lastName->clear();
//    ui->lineEdit_email->clear();
//    ui->lineEdit_password->clear();
//    ui->lineEdit_country->clear();
//    ui->lineEdit_university->clear();
//    ui->comboBox_semester->clear();
//    ui->spinBox_duration->clear();
}


void NewTeacher::on_cancelButton_clicked()
{
    hide();
}
