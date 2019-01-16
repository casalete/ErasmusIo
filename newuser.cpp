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
    QSqlDatabase db_register = QSqlDatabase::addDatabase("QPSQL","erasmusio");
        db_register.setHostName("localhost");  // host
        db_register.setDatabaseName("erasmusio");
        db_register.setUserName("erasmusio");
        db_register.setPassword("erasmusio");

        bool ok = db_register.open();

        if (!ok)
            qDebug() << "Eroare la baza de date!";

        QString firstname = ui->lineEdit_firstName->text();
        QString lastname = ui->lineEdit_lastName->text();
        QString email = ui->lineEdit_email->text();
        QString password = ui->lineEdit_password->text();

        QString role = "Student";  //TODO
        int id = 0; //TODO

        QSqlQuery query( QSqlDatabase::database( "erasmusio" ) );
        query.prepare("INSERT INTO users (id, first_name, last_name, email, password, role) "
                   "VALUES (?,?,?,?,?,?)");

        query.addBindValue(id);
        query.addBindValue(firstname);
        query.addBindValue(lastname);
        query.addBindValue(email);
        query.addBindValue(password);
        query.addBindValue(role);


        query.exec();

        QMessageBox::information(this,"titlu","S-a creat utilizatorul!");
        ui->lineEdit_firstName->clear();
        ui->lineEdit_lastName->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();

        db_register.close();
        QSqlDatabase::removeDatabase("erasmusio");
}
