#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

private:
    Ui::Widget *ui;

    enum Column{
        COURSE, TEACHER, NROFHOURS, NROFCREDITPOINTS, OPTIONALITY
    };
};

#endif // WIDGET_H
