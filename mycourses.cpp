#include "mycourses.h"
#include "ui_mycourses.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

MyCourses::MyCourses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyCourses)
{
    ui->setupUi(this);
    setWindowTitle("My Courses");


}

MyCourses::~MyCourses()
{
    delete ui;
}

void MyCourses::on_back_clicked()
{
    hide();
}
void MyCourses::init(int student_id){
    int nrCourses = 0;
    QString studentIDString = QString::number(student_id);
    QSqlDatabase db_courses;
    db_courses = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_myCourses = new QSqlQuery(db_courses);

    QString queryString = "SELECT name, teacher_name, no_credits, optionality, no_hours "
                          "FROM public.course "
                          "WHERE id in (SELECT id_course FROM public.student_course WHERE id_student ='"+studentIDString+ "')";

    query_myCourses->prepare(queryString);
    query_myCourses->exec();
    while(query_myCourses->next()){
        nrCourses++;
    }
    modalTable->setQuery(*query_myCourses);
    ui->tableView->setModel(modalTable);
    ui->nrCoursesLabel->setText(QString::number(nrCourses));
}
