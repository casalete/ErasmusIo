#include "menustudent.h"
#include "ui_menustudent.h"

MenuStudent::MenuStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuStudent)
{
    ui->setupUi(this);
}

MenuStudent::~MenuStudent()
{
    delete ui;
}

void MenuStudent::on_pushButton_clicked()
{
    hide();
    widget = new Widget();
    widget->show();
}
