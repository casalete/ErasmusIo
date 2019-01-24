#include "details.h"
#include "ui_details.h"
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

Details::Details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
      setWindowTitle("Details");
}

Details::~Details()
{
    delete ui;
}

void Details::on_viewUniversities_clicked()
{
   // hide();
    viewunis = new ViewUnis();
    viewunis->show();

}
//SELECT * FROM public.student WHERE id IN(SELECT id_student FROM public.student_course WHERE id_course = (SELECT id FROM public.course WHERE public.course.name ='" + courseNameString+ "')");

void Details::on_back_clicked(){
    hide();
}

void Details::init(int id){
    id_teacher = id;
    QString idTeacherString = QString::number(id_teacher);
    QSqlDatabase db_course;
    db_course = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalComboBox = new QSqlQueryModel();
    QSqlQuery* query_course = new QSqlQuery(db_course);
    query_course->prepare("SELECT name from course WHERE id_teacher ='" + idTeacherString + "'");
    query_course->exec();
    modalComboBox->setQuery(*query_course);
    ui->comboBox_selectCourse->setModel(modalComboBox);
}

void Details::on_viewStudentsButton_clicked()
{
    int k = 0;
    QString courseNameString = ui->comboBox_selectCourse->currentText();
    QSqlDatabase db_student;
    db_student = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_student = new QSqlQuery(db_student);
    query_student->prepare("SELECT * FROM public.student WHERE id IN(SELECT id_student FROM public.student_course WHERE id_course = (SELECT id FROM public.course WHERE public.course.name ='" + courseNameString+ "'))");
    query_student->exec();
    while(query_student->next()){
        k++;
    }

    modalTable->setQuery(*query_student);
    ui->tableView->setModel(modalTable);
    QString nrStud = QString::number(k);
    ui->nrStudLabel->setText(nrStud);
}

void Details::on_search_clicked()
{
    QString studentName = ui->lineEdit_searchStudent->text();
    QSqlDatabase db_student;
    db_student = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_student = new QSqlQuery(db_student);
    query_student->prepare("SELECT * FROM student where last_name ='"+studentName+"'");
    query_student->exec();
    modalTable->setQuery(*query_student);
    ui->tableView->setModel(modalTable);

}
