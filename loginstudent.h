#ifndef LOGINSTUDENT_H
#define LOGINSTUDENT_H

#include <QWidget>

namespace Ui {
class LogInStudent;
}

class LogInStudent : public QWidget
{
    Q_OBJECT

public:
    explicit LogInStudent(QWidget *parent = nullptr);
    ~LogInStudent();

private:
    Ui::LogInStudent *ui;
};

#endif // LOGINSTUDENT_H
