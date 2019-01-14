#ifndef MENUTEACHER_H
#define MENUTEACHER_H

#include <QDialog>

#include "widget.h"

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
    void on_pushButton_clicked();

private:
    Ui::MenuTeacher *ui;
    Widget * widget;
};

#endif // MENUTEACHER_H
