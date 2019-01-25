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
      setWindowTitle("New Student");
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
{
    //TODO - get values from ui

    QString form_first_name = ui->lineEdit_firstName->text();
    QString form_last_name = ui->lineEdit_lastName->text();
    QString form_email = ui->lineEdit_email->text();
    QString form_password = ui->lineEdit_password->text();
    QString form_university_name = ui->lineEdit_university->text();
    QString form_country = ui->lineEdit_country->text();
    QVariant form_semester = ui->comboBox_semester->currentText();
    int form_study_duration = ui->spinBox_duration->value();
    //QString role = "STUDENT";

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("INSERT INTO student (first_name, last_name, email, country, study_duration, semester, university_name,  password)"
               "VALUES (?,?,?,?,?,?,?,?)");

    query.addBindValue(form_first_name);
    query.addBindValue(form_last_name);
    query.addBindValue(form_email);
    query.addBindValue(form_country);
    query.addBindValue(form_study_duration);
    query.addBindValue(form_semester.toString());
    //query.addBindValue(form_study_form);
    query.addBindValue(form_university_name);
     query.addBindValue(form_password);


   // query.addBindValue(role);


     if(query.exec()){
         QMessageBox::information(this,tr("SUCCESS"),tr("STUDENT ADDED SUCCESFULLY"));
          hide();
     }
     else{
         QMessageBox::critical(this,tr("error::"),tr("FAILED TO ADD STUDENT"));
     }

    ui->lineEdit_firstName->clear();
    ui->lineEdit_lastName->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_password->clear();
    ui->lineEdit_country->clear();
    ui->lineEdit_university->clear();
    ui->comboBox_semester->clear();
    ui->spinBox_duration->clear();






}
    //QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
}

// TODO- close database connection


    //QMessageBox::information( "S-a creat utilizatorul!");

   // QSqlDatabase::removeDatabase("erasmusio");

   // QMessageBox::information(this,"titlu","S-a creat utilizatorul!");

//    ui->lineEdit_firstName->clear();
//    ui->lineEdit_lastName->clear();
//    ui->lineEdit_email->clear();
//    ui->lineEdit_password->clear();


void NewStudent::on_cancelButton_clicked()
{
    hide();
}
