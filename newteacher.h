#ifndef NEWTEACHER_H
#define NEWTEACHER_H

#include <QWidget>

namespace Ui {
class NewTeacher;
}

class NewTeacher : public QWidget
{
    Q_OBJECT

public:
    explicit NewTeacher(QWidget *parent = nullptr);
    ~NewTeacher();

private slots:
    void on_submitButton_clicked();

private:
    Ui::NewTeacher *ui;
};

#endif // NEWTEACHER_H
