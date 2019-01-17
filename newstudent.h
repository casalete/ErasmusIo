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

private slots:
    void on_submitButton_clicked();

private:
    Ui::NewStudent *ui;
};

#endif // NEWSTUDENT_H
