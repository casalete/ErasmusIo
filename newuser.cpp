#include "newuser.h"
#include "ui_newuser.h"

#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>

NewUser::NewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::on_submitButton_clicked()
{
    QSqlDatabase dblogin = QSqlDatabase::addDatabase("QMYSQL","mip");
        dblogin.setHostName("localhost");  // host
        dblogin.setDatabaseName("proiect_poo");
        dblogin.setUserName("root");
        dblogin.setPassword("bomboane");

        bool ok = dblogin.open();

        if (!ok)
            qDebug() << "Eroare la baza de date!";

    QString firstname = ui->lineEdit_firstName->text();
        QString lastname = ui->lineEdit_lastName->text();
        QString email = ui->lineEdit_email->text();
        QString password = ui->lineEdit_password->text();

        QSqlQuery query( QSqlDatabase::database( "mip" ) );
        query.prepare("INSERT INTO newuser (FirstName, LastName, Email, Password) "
                   "VALUES (?,?,?,?)");

        query.addBindValue(firstname);
        query.addBindValue(lastname);
        query.addBindValue(email);
        query.addBindValue(password);

        query.exec();

        QMessageBox::information(this,"titlu","S-a creat utilizatorul!");
        ui->lineEdit_firstName->clear();
        ui->lineEdit_lastName->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();

        dblogin.close();
        QSqlDatabase::removeDatabase("proiect_poo");
}
