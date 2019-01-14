#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "newuser.h"
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

private slots:
    void on_newUserButton_clicked();

    void on_studentButton_clicked();

    void on_teacherButton_clicked();

private:
    Ui::MainWindow *ui;
    NewUser * newuser;
    LoginStudent * loginstudent;
    LoginTeacher * loginteacher;
};

#endif // MAINWINDOW_H
