#include "coursedialog.h"
#include "ui_coursedialog.h"
#include "mainwindow.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

CourseDialog::CourseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseDialog)
{
    ui->setupUi(this);
    setWindowTitle("Courses");

    ui->comboBox_optionality->addItem("MANDATORY");
    ui->comboBox_optionality->addItem("OPTIONAL");

}

CourseDialog::~CourseDialog()
{
    delete ui;
}


QString CourseDialog::course() const{
    return ui->course->text();
}

QString CourseDialog::teacher() const{
    return ui->teacher->text();
}

int CourseDialog::nrH() const{
    return ui->nrH->value();
}

int CourseDialog::nrCP() const{
    return ui->nrCP->value();
}

QString CourseDialog::optionality() const{
    return ui->comboBox_optionality->currentText();
}

void CourseDialog::on_save_clicked()
{
    //TODO - get values from ui

    QString form_name = ui->course->text();
    QString form_teacherName = ui->teacher->text();
    int form_no_credits = ui->nrCP->value();
    QString form_optionality = ui->comboBox_optionality->currentText();
    int form_no_hours = ui->nrH->value();


    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("INSERT INTO course (name, teacher_name, no_credits, optionality,no_hours)"
               "VALUES (?,?,?,?,?)");

    query.addBindValue(form_name);
    query.addBindValue(form_teacherName);
    query.addBindValue(form_no_credits);
    query.addBindValue(form_optionality);
    query.addBindValue(form_no_hours);
   // query.addBindValue(role);

    query.exec();

    ui->course->clear();
    ui->teacher->clear();
    ui->nrCP->clear();
    ui->comboBox_optionality->clear();
    ui->nrH->clear();


}

void CourseDialog::on_close_clicked()
{
    hide();
}


