#ifndef COURSEINFO_H
#define COURSEINFO_H

#include <QDialog>

namespace Ui {
class CourseINFO;
}

class CourseINFO : public QDialog
{
    Q_OBJECT

public:
    explicit CourseINFO(QWidget *parent = 0);
    ~CourseINFO();

private:
    Ui::CourseINFO *ui;
};

#endif // COURSEINFO_H
