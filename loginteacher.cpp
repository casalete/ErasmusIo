#include "loginteacher.h"
#include "ui_loginteacher.h"

#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include "mainwindow.h"


LoginTeacher::LoginTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginTeacher)
{
    ui->setupUi(this);
}

LoginTeacher::~LoginTeacher()
{
    delete ui;
}

void LoginTeacher::on_loginButton_clicked()
{
    QString email = ui->lineEdit_usernamet->text();
    QString password = ui->lineEdit_passwordt->text();
    MainWindow m;
    m.openConnection();
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    //query.prepare("SELECT * from useres where email="+email+"'and password ='"+password);
    query.prepare("SELECT email, password FROM teacher");
    query.exec();
    int k=0;
    while (query.next())
    {

        QString emailFromDB = query.value(0).toString();
        QString passwordFromDb = query.value(1).toString();

       if (email == emailFromDB && password == passwordFromDb)
           {
               k++;
           }
    }
    if(k>0){
        //dblogin.close();
        //m.closeConnection();
        this->hide();
        menuteacher = new MenuTeacher(this);
        menuteacher->show();
    }
    else
        QMessageBox::warning(this,"Autentificare","Date de autentificare incorecte!");

    //ui->lineEdit_username->clear();
   // ui->lineEdit_password->clear();
}

void LoginTeacher::on_newTeacherButton_clicked()
{
    hide();
    newTeacher = new NewTeacher();
    newTeacher->show();

}
