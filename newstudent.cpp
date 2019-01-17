#include "newstudent.h"
#include "ui_newstudent.h"
#include "mainwindow.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

NewStudent::NewStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewStudent)
{
    ui->setupUi(this);

    ui->comboBox_semester->addItem("Semester 1");
    ui->comboBox_semester->addItem("Semester 2");
    ui->comboBox_semester->addItem("Whole year");

}

NewStudent::~NewStudent()
{
    delete ui;
}

void NewStudent::on_submitButton_clicked()
{

    //TODO - get values from ui

//    QString firstname = ui->lineEdit_firstName->text();
//    QString lastname = ui->lineEdit_lastName->text();
//    QString email = ui->lineEdit_email->text();
//    QString password = ui->lineEdit_password->text();
    //    QString country = ui->lineEdit_country->text();
    //    Qstring semester = ui->lineEdit_


    //TODO - ROLE
    QString role = "STUDENT";

//    QString role;
//    if(ui->studentRadioButton->isChecked())
//        role = "STUDENT";
//    else if (ui->teacherRadioButton->isChecked()){

//        if(email == "admin")
//            role = "ADMIN";
//        else
//            role = "TEACHER";
//    }


    MainWindow m;
    m.openConnection();
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query( db );
    query.prepare("INSERT INTO student (first_name, last_name, email, country, password, study_duration, semester, study_form, university_name)"
               "VALUES (?,?,?,?,?,?,?,?,?)");

//    query.addBindValue(form_first_name);
//    query.addBindValue(form_last_name);
//    query.addBindValue(form_email);
//    query.addBindValue(form_password);
//    query.addBindValue(study_duration);
//    query.addBindValue(semester);
//    query.addBindValue(study_form);
//    query.addBindValue(university_name);


   // query.addBindValue(role);


    query.exec();
}

// TODO- close database connection


    //QMessageBox::information( "S-a creat utilizatorul!");

   // QSqlDatabase::removeDatabase("erasmusio");

   // QMessageBox::information(this,"titlu","S-a creat utilizatorul!");

//    ui->lineEdit_firstName->clear();
//    ui->lineEdit_lastName->clear();
//    ui->lineEdit_email->clear();
//    ui->lineEdit_password->clear();

