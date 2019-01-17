#ifndef CREATESTUDENT_H
#define CREATESTUDENT_H

#include <QWidget>

namespace Ui {
class CreateStudent;
}

class CreateStudent : public QWidget
{
    Q_OBJECT

public:
    explicit CreateStudent(QWidget *parent = nullptr);
    ~CreateStudent();

private:
    Ui::CreateStudent *ui;
};

#endif // CREATESTUDENT_H
