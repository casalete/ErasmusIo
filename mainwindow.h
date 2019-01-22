#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "loginstudent.h"
#include "loginteacher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QSqlDatabase dblogin;

    bool openConnection(){

        dblogin = QSqlDatabase::addDatabase("QPSQL");
        dblogin.setHostName("localhost");  // host
        dblogin.setDatabaseName("erasmusio");
        dblogin.setUserName("erasmusio");
        dblogin.setPassword("erasmusio");
        if(!dblogin.open()){
            qDebug()<<("Failed to open database");
            return false;
        }
        else{
            qDebug()<<("Connection to database succesfull");
            return true;
        }
    }

private slots:

    void on_studentButton_clicked();

    void on_teacherButton_clicked();

private:
    Ui::MainWindow *ui;
    LoginStudent * loginstudent;
    LoginTeacher * loginteacher;
};

#endif // MAINWINDOW_H
