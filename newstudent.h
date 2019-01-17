#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H

#include <QWidget>

namespace Ui {
class NewStudent;
}

class NewStudent : public QWidget
{
    Q_OBJECT

public:
    explicit NewStudent(QWidget *parent = nullptr);
    ~NewStudent();

private:
    Ui::NewStudent *ui;
};

#endif // NEWSTUDENT_H
