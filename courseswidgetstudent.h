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

private:
    Ui::CoursesWidgetStudent *ui;
};

#endif // COURSESWIDGETSTUDENT_H
