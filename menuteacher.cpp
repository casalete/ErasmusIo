#include "menuteacher.h"
#include "ui_menuteacher.h"

MenuTeacher::MenuTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuTeacher)
{
    ui->setupUi(this);
}

MenuTeacher::~MenuTeacher()
{
    delete ui;
}

void MenuTeacher::on_pushButton_clicked()
{
    hide();
    widget = new Widget();
    widget->show();
}
