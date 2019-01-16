#include "menustudent.h"
#include "ui_menustudent.h"

#include <QLineEdit>

#include <QMessageBox>
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>

MenuStudent::MenuStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuStudent)
{
    ui->setupUi(this);

    QSqlDatabase dblogin = QSqlDatabase::addDatabase("QPSQL","erasmusio");
        dblogin.setHostName("localhost");  // host
        dblogin.setDatabaseName("erasmusio");
        dblogin.setUserName("erasmusio");
        dblogin.setPassword("erasmusio");

        bool ok = dblogin.open();

        if (!ok)
            qDebug() << "Eroare la baza de date!";

        QSqlQuery query( QSqlDatabase::database( "erasmusio" ) );

        query.exec("SELECT first_name, last_name, email, password FROM users"
                   "WHERE email = email");

        while (query.next())
        {
            QString firstname = query.value(0).toString();
            QString lastname = query.value(1).toString();
            QString email = query.value(2).toString();
            QString password = query.value(3).toString();
        }

        //ui->label_11->setText(firstname);
        //ui->lineEdit_lastName->setText(lastname);
        //ui->lineEdit_email->setText(email);
        //ui->lineEdit_password->setText(password);

        dblogin.close();
        QSqlDatabase::removeDatabase("proiect_poo");

        ui->lineEdit_firstName->clear();
        ui->lineEdit_lastName->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();
}

MenuStudent::~MenuStudent()
{
    delete ui;
}

void MenuStudent::on_coursesButton_clicked()
{
    hide();
    widget = new Widget();
    widget->show();
}
