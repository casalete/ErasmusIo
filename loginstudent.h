#ifndef LOGINSTUDENT_H
#define LOGINSTUDENT_H

#include <QDialog>
#include "QSql"
#include "QSqlDatabase"
#include "menustudent.h"
#include "QtDebug"
#include "newstudent.h"

namespace Ui {
class LoginStudent;
}

class LoginStudent : public QDialog
{
    Q_OBJECT

//public:
//    QSqlDatabase dblogin;

//    bool openConnection(){

//        dblogin = QSqlDatabase::addDatabase("QPSQL");
//        dblogin.setHostName("localhost");  // host
//        dblogin.setDatabaseName("erasmusio");
//        dblogin.setUserName("erasmusio");
//        dblogin.setPassword("erasmusio");
//        if(!dblogin.open()){
//            qDebug()<<("Failed to open database");
//            return false;
//        }
//        else{
//            qDebug()<<("Connection to database succesfull");
//            return true;
//        }
//    }
//    void closeConnection(){

//        QString connectionName = dblogin.connectionName();
//        dblogin.close();
//        dblogin = QSqlDatabase();
//        QSqlDatabase::removeDatabase(dblogin.connectionName());

//        qDebug()<<("Connection to database closed");
//    }



public:
    explicit LoginStudent(QWidget *parent = nullptr);
    ~LoginStudent();

//public:
//    int getId(){
//        return login_id;
//    }

//public:
//    int login_id;

private slots:
    void on_loginButton_clicked();

    void on_newStudentButton_clicked();

private:
    Ui::LoginStudent *ui;
    MenuStudent * menustudent;
    NewStudent * newStudent;
};

#endif // LOGINSTUDENT_H
