#ifndef MENUSTUDENT_H
#define MENUSTUDENT_H

#include <QDialog>
#include "courseswidgetstudent.h"

namespace Ui {
class MenuStudent;
}

class MenuStudent : public QDialog
{
    Q_OBJECT

public:
    explicit MenuStudent(QWidget *parent = nullptr);

    ~MenuStudent();
//    MenuStudent(int id){
//    student_id = id;
//}




private slots:
    void on_coursesButton_clicked();

private:
    Ui::MenuStudent *ui;
    CoursesWidgetStudent * widget;


private:
    int student_id;

public:
    void setStudentId(int id){
        student_id = id;
    }
    int getStudentId(){
        return student_id;
    }
    void doQuery(int);

public slots:
    void setValueFromSignal(int val);
};

#endif // MENUSTUDENT_H

