#ifndef LOGINTEACHER_H
#define LOGINTEACHER_H

#include <QDialog>

namespace Ui {
class LogInTeacher;
}

class LogInTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit LogInTeacher(QWidget *parent = nullptr);
    ~LogInTeacher();

private:
    Ui::LogInTeacher *ui;
};

#endif // LOGINTEACHER_H
