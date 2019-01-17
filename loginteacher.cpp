#include "loginteacher.h"
#include "ui_loginteacher.h"

#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>

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
//    QSqlDatabase dblogin = QSqlDatabase::addDatabase("QMYSQL","mip");
//        dblogin.setHostName("localhost");  // host
//        dblogin.setDatabaseName("proiect_poo");
//        dblogin.setUserName("root");
//        dblogin.setPassword("bomboane");

//        QString username = ui->lineEdit_usernamet->text();
//        QString password = ui->lineEdit_passwordt->text();

//        bool ok = dblogin.open();

//        if (!ok)
//            qDebug() << "Eroare la baza de date!";

//        QSqlQuery query( QSqlDatabase::database( "mip" ) );

//        query.exec("SELECT Username, Password FROM loginteacher");

//        int k=0;
//        while (query.next())
//        {
//            QString name = query.value(0).toString();
//            QString pass = query.value(1).toString();

//            if (username == name && password == pass)
//            {
//                k++;
//                hide();
//                menuteacher = new MenuTeacher(this);
//                menuteacher->show();
//            }
//        }
//        if (k == 0)
//        {
//            QMessageBox::warning(this,"Autentificare","Date de autentificare incorecte!");
//        }

//        dblogin.close();
//        QSqlDatabase::removeDatabase("proiect_poo");

//        ui->lineEdit_usernamet->clear();
//        ui->lineEdit_passwordt->clear();
}

void LoginTeacher::on_newTeacherButton_clicked()
{
    hide();
    newTeacher = new NewTeacher();
    newTeacher->show();

}
