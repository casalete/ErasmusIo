#ifndef DIALOGCOURSESSTUDENT_H
#define DIALOGCOURSESSTUDENT_H

#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>

namespace Ui {
class DialogCoursesStudent;
}

class DialogCoursesStudent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCoursesStudent(QWidget *parent = 0);
    ~DialogCoursesStudent();

private:
    Ui::DialogCoursesStudent *ui;

    QStandardItemModel *model;
};

#endif // DIALOGCOURSESSTUDENT_H
