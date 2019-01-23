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

    ui->comboBox_optionality->addItem("MANDATORY");
    ui->comboBox_optionality->addItem("OPTIONAL");

}

CourseDialog::~CourseDialog()
{
    delete ui;
}

void CourseDialog::on_buttonBox_accepted()
{

     accept();
//    //TODO - get values from ui

//    QString form_name = ui->course->text();
//    QString form_name_teacher = ui->teacher->text();
//     int form_no_hours = ui->nrH->value();
//      int form_no_credits = ui->nrCP->value();
//    QVariant form_optionality = ui->comboBox_optionality->currentText();

//    MainWindow m;
//    m.openConnection();
//    QSqlDatabase db = QSqlDatabase::database();
//    QSqlQuery query(db);
//    query.prepare("INSERT INTO course (name, name_teacher, no_credits, optionality, no_hours_w)"
//               "VALUES (?,?,?,?,?)");

//    query.addBindValue(form_name);
//    query.addBindValue(form_name_teacher);
//    query.addBindValue(form_no_hours);
//    query.addBindValue(form_no_credits);
//    query.addBindValue(form_optionality);

//    query.exec();

//    ui->course->clear();
//    ui->teacher->clear();
//    ui->nrH->clear();
//    ui->nrCP->clear();
//    ui->comboBox_optionality->clear();




}

void CourseDialog::on_buttonBox_rejected()
{
    reject();
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
