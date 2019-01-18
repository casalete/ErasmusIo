#ifndef MENUSTUDENT_H
#define MENUSTUDENT_H

#include <QDialog>
#include "widget.h"

namespace Ui {
class MenuStudent;
}

class MenuStudent : public QDialog
{
    Q_OBJECT

public:
    explicit MenuStudent(QWidget *parent = nullptr);
    ~MenuStudent();

private slots:
    void on_coursesButton_clicked();

private:
    Ui::MenuStudent *ui;
    Widget * widget;


public:
    int student_id;

public:
    void setStudentId(int id){
        student_id = id;
    }
};

#endif // MENUSTUDENT_H

