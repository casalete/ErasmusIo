#ifndef LOGINTEACHER_H
#define LOGINTEACHER_H

#include <QDialog>

#include "menuteacher.h"
#include "newteacher.h"

namespace Ui {
class LoginTeacher;
}

class LoginTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit LoginTeacher(QWidget *parent = nullptr);
    ~LoginTeacher();


private slots:
    void on_loginButton_clicked();

    void on_newTeacherButton_clicked();

    void on_backButton_clicked();

private:
    Ui::LoginTeacher *ui;
    MenuTeacher * menuteacher;
    NewTeacher * newTeacher;
};

#endif // LOGINTEACHER_H

