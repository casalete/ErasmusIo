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

    accept();

//    //TODO - get values from ui

//    QString form_name = ui->course->text();
//    QString form_teacherName = ui->teacher->text();
//    int form_no_credits = ui->nrCP->value();
//    QString form_optionality = ui->comboBox_optionality->currentText();
//    int form_no_hours = ui->nrH->value();




//    QSqlDatabase db_course;
//    db_course = QSqlDatabase::database("QPSQL");
//    QSqlQuery query_teacher_id(db_course);

//    QString queryString = "SELECT id from teacher where last_name ='" + teacherName + "'";
//    query_teacher_id.prepare(queryString);
//    query_teacher_id.exec();
//    int teacherID;
//    while(query_teacher_id.next())
//              {
//               teacherID = query_teacher_id.value(0).toInt();
//              }

//       //query.prepare("SELECT first_name, last_name, email, password FROM student where id ='" + id_string + "'");
//        QSqlQuery query_add_course(db_course);
//        query_add_course.prepare("INSERT into course (name, teacher_name, no_credits, optionality, no_hours, id_teacher)"
//                "VALUES(?,?,?,?,?,?)");
//        query_add_course.addBindValue(courseName);
//        query_add_course.addBindValue(teacherName);
//        query_add_course.addBindValue(nrCreditPoints);
//        query_add_course.addBindValue(optionality);
//        query_add_course.addBindValue(nrHours);
//        query_add_course.addBindValue(teacherID);











//    QSqlDatabase db = QSqlDatabase::database();
//    QSqlQuery query(db);
//    query.prepare("INSERT INTO course (name, teacher_name, no_credits, optionality,no_hours,id_teacher)"
//               "VALUES (?,?,?,?,?,?)");

//    query.addBindValue(form_name);
//    query.addBindValue(form_teacherName);
//    query.addBindValue(form_no_credits);
//    query.addBindValue(form_optionality);
//    query.addBindValue(form_no_hours);
//    query_add_course.addBindValue(teacherID);
//   // query.addBindValue(role);

//    query.exec();

//    ui->course->clear();
//    ui->teacher->clear();
//    ui->nrCP->clear();
//    ui->comboBox_optionality->clear();
//    ui->nrH->clear();


}

void CourseDialog::on_close_clicked()
{
    reject();
}


