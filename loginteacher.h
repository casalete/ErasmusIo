#ifndef LOGINTEACHER_H
#define LOGINTEACHER_H

#include <QDialog>

#include "menuteacher.h"

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
    void on_pushButton_clicked();

private:
    Ui::LoginTeacher *ui;
    MenuTeacher * menuteacher;
};

#endif // LOGINTEACHER_H

