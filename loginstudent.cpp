#include "loginstudent.h"
#include "ui_loginstudent.h"

#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include "mainwindow.h"

LoginStudent::LoginStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginStudent)
{
    ui->setupUi(this);
    //openConnection();
//    if (!openConnection())
//        qDebug() << "Eroare la baza de date!";
}

LoginStudent::~LoginStudent()
{
    delete ui;
}

void LoginStudent::on_loginButton_clicked()
{
        QString email = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();
        MainWindow m;
        m.openConnection();
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query(db);
        //query.prepare("SELECT * from useres where email="+email+"'and password ='"+password);
        query.prepare("SELECT email, password, id FROM student");
        query.exec();
        int k=0;
        while (query.next())
        {

            QString emailFromDB = query.value(0).toString();
            QString passwordFromDb = query.value(1).toString();


           if (email == emailFromDB && password == passwordFromDb)
               {
                   k++;
                   //login_id = query.value(2).toInt();
               }
        }
        if(k>0){
            //dblogin.close();
            //m.closeConnection();
            this->hide();
            menustudent = new MenuStudent(this);
            menustudent->show();
        }
        else
            QMessageBox::warning(this,"Autentificare","Date de autentificare incorecte!");

        //ui->lineEdit_username->clear();
       // ui->lineEdit_password->clear();

}

void LoginStudent::on_newStudentButton_clicked()
{
   // MainWindow m;
   // m.closeConnection();
    hide();
    newStudent = new NewStudent();
    newStudent->show();

}
