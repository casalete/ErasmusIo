#ifndef LOGINSTUDENT_H
#define LOGINSTUDENT_H

#include <QDialog>

#include "menustudent.h"

namespace Ui {
class LoginStudent;
}

class LoginStudent : public QDialog
{
    Q_OBJECT

public:
    explicit LoginStudent(QWidget *parent = nullptr);
    ~LoginStudent();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginStudent *ui;
    MenuStudent * menustudent;
};

#endif // LOGINSTUDENT_H
