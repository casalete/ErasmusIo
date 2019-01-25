#ifndef COURSESWIDGETSTUDENT_H
#define COURSESWIDGETSTUDENT_H

#include <QWidget>

namespace Ui {
class CoursesWidgetStudent;
}

class CoursesWidgetStudent : public QWidget
{
    Q_OBJECT

public:
    explicit CoursesWidgetStudent(QWidget *parent = 0);
    ~CoursesWidgetStudent();

private slots:
    void on_back_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::CoursesWidgetStudent *ui;
    int id_student;

public:
  void init(int);
  void reset();
};

#endif // COURSESWIDGETSTUDENT_H
