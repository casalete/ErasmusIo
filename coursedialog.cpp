#include "coursedialog.h"
#include "ui_coursedialog.h"

CourseDialog::CourseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseDialog)
{
    ui->setupUi(this);
}

CourseDialog::~CourseDialog()
{
    delete ui;
}

void CourseDialog::on_buttonBox_accepted()
{
    accept();
}

void CourseDialog::on_buttonBox_rejected()
{
    reject();
}

QString CourseDialog::course() const{
    return ui->courseName->text();
}

QString CourseDialog::teacher() const{
    return ui->teacherName->text();
}

int CourseDialog::nrH() const{
    return ui->nrH->value();
}
