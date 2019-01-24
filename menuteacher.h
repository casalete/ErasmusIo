#ifndef MENUTEACHER_H
#define MENUTEACHER_H

#include <QDialog>

#include "widget.h"
#include "details.h"

namespace Ui {
class MenuTeacher;
}

class MenuTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit MenuTeacher(QWidget *parent = nullptr);

    ~MenuTeacher();

private slots:
    void on_coursesButton_clicked();
    void on_detailsButton_clicked();

private:
    Ui::MenuTeacher *ui;
    Widget * widget;
    Details * details;

private:
    int teacher_id;

public:
   void doQuery(int);


};

#endif // MENUTEACHER_H
