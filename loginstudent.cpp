#include "loginstudent.h"
#include "ui_loginstudent.h"

#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>

LoginStudent::LoginStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginStudent)
{
    ui->setupUi(this);
}

LoginStudent::~LoginStudent()
{
    delete ui;
}

void LoginStudent::on_loginButton_clicked()
{


    hide();
    menustudent = new MenuStudent(this);
    menustudent->show();

//    QSqlDatabase dblogin = QSqlDatabase::addDatabase("QMYSQL","mip");
//        dblogin.setHostName("localhost");  // host
//        dblogin.setDatabaseName("proiect_poo");
//        dblogin.setUserName("root");
//        dblogin.setPassword("bomboane");

//        QString username = ui->lineEdit_username->text();
//        QString password = ui->lineEdit_password->text();

//        bool ok = dblogin.open();

//        if (!ok)
//            qDebug() << "Eroare la baza de date!";

//        QSqlQuery query( QSqlDatabase::database( "mip" ) );

//        query.exec("SELECT Username, Password FROM loginstudent");

//        int k=0;
//        while (query.next())
//        {
//            QString name = query.value(0).toString();
//            QString pass = query.value(1).toString();
//            //int salary = query.value(1).toInt();   in caz ca vreau si verification code

//            if (username == name && password == pass)
//            {
//                k++;
//                hide();
//                menustudent = new MenuStudent(this);
//                menustudent->show();
//            }
//        }
//        if (k == 0)
//        {
//            QMessageBox::warning(this,"Autentificare","Date de autentificare incorecte!");
//        }

//        dblogin.close();
//        QSqlDatabase::removeDatabase("proiect_poo");

//        ui->lineEdit_username->clear();
//        ui->lineEdit_password->clear();
}
