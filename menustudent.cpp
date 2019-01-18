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
    //LoginStudent student;
    //int id = student.getId();
   // char buffer [5];
   // sprintf(buffer, "%d", id);
//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","db1");
//    db.setHostName("localhost");  // host
//    db.setDatabaseName("erasmusio");
//    db.setUserName("erasmusio");
//    db.setPassword("erasmusio");
//    if(!db.open()){
//        qDebug()<<("Failed to open database");
//    }
//    MainWindow mw;
//    mw.openConnection();
//    QSqlDatabase db = QSqlDatabase::database();
//    QSqlQuery query(db);
//   // QString queryStr = "SELECT first_name, last_name, email, password FROM users where id '" + QString(buffer) + "'";
//    query.prepare("SELECT first_name, last_name, email, password FROM users");

//    query.exec();

//    while(query.next()){
//         QString firstname = query.value(0).toString();
//           QString lastname = query.value(1).toString();
//           QString email = query.value(2).toString();
//           QString password = query.value(3).toString();
//       }


//    LoginStudent ls;
//    QSqlDatabase db = QSqlDatabase::database("erasmusio");
//    QSqlQuery query(db);
//    query.prepare("SELECT first_name, last_name, email, password FROM users");
//    query.exec();
//    ls.closeConnection();
//    QSqlDatabase db = QSqlDatabase::database("erasmusio");
//    QSqlQuery query(db);
//    query.prepare("SELECT first_name, last_name, email, password FROM users");
//    query.exec();
//    while(query.next()){
//        QString firstname = query.value(0).toString();
//        QString lastname = query.value(1).toString();
//        QString email = query.value(2).toString();
//        QString password = query.value(3).toString();
//    }


//    QSqlDatabase dblogin = QSqlDatabase::addDatabase("QPSQL","erasmusio");
//        dblogin.setHostName("localhost");  // host
//        dblogin.setDatabaseName("erasmusio");
//        dblogin.setUserName("erasmusio");
//        dblogin.setPassword("erasmusio");


//        QSqlDatabase dblogin = QSqlDatabase::database("erasmusio");
//        bool ok = dblogin.open();

//        if (!ok)
//            qDebug() << "Eroare la baza de date!";

//        QSqlQuery query(dblogin);

//        query.exec("SELECT first_name, last_name, email, password FROM users");

//        while (query.next())
//        {
//            QString firstname = query.value(0).toString();
//            QString lastname = query.value(1).toString();
//            QString email = query.value(2).toString();
//            QString password = query.value(3).toString();
//        }

//        //ui->label_11->setText(firstname);
//        //ui->lineEdit_lastName->setText(lastname);
//        //ui->lineEdit_email->setText(email);
//        //ui->lineEdit_password->setText(password);

//    }
//    // QSqlDatabase::removeDatabase("erasmusio");


//        ui->lineEdit_firstName->clear();
//        ui->lineEdit_lastName->clear();
//        ui->lineEdit_email->clear();
//        ui->lineEdit_password->clear();



    //int test = getStudentId();
    QSqlDatabase db_menustudent;
    db_menustudent = QSqlDatabase::addDatabase("QPSQL","menustudent");
    db_menustudent.setHostName("localhost");  // host
    db_menustudent.setDatabaseName("erasmusio");
    db_menustudent.setUserName("erasmusio");
    db_menustudent.setPassword("erasmusio");
    db_menustudent.open();
    QSqlQuery query(db_menustudent);
    QString id_string = QString::number(student_id);

    QString queryString = "SELECT first_name, last_name, email, password FROM student where id ='" + id_string + "'";
    // query.prepare("SELECT first_name, last_name, email,country,university_name, password FROM student ");
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

               QString duration = query.value(4).toString();
               ui->lineEdit_duration->setText(duration);

               QString semester = query.value(5).toString();
               ui->lineEdit_period->setText(semester);

               QString university_name = query.value(6).toString();
               ui->lineEdit_university->setText(university_name);

               QString password = query.value(7).toString();
               ui->lineEdit_password->setText(password);
           }



//    if(!dblogin.open()){
//        qDebug()<<("Failed to open database");
//        return false;
//    }
//    else{
//        qDebug()<<("Connection to database succesfull");
//        return true;
}



MenuStudent::~MenuStudent()
{
    delete ui;
}

void MenuStudent::on_coursesButton_clicked()
{
    widget = new CoursesWidgetStudent();
    widget->show();
}

void MenuStudent::setValueFromSignal(int val){
    student_id = val;
}
