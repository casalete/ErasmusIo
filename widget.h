#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "coursedialog.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_addCourse_clicked();
    void on_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    CourseDialog * coursedialog;

};

#endif // WIDGET_H
