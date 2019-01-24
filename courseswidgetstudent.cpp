#include "courseswidgetstudent.h"
#include "ui_courseswidgetstudent.h"
#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
CoursesWidgetStudent::CoursesWidgetStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoursesWidgetStudent)
{
    ui->setupUi(this);
}

CoursesWidgetStudent::~CoursesWidgetStudent()
{
    delete ui;
}

void CoursesWidgetStudent::on_back_clicked()
{
    hide();
}

void CoursesWidgetStudent::init(int id){
    id_student = id;
    QString id_student_string = QString::number(id_student);
    QSqlDatabase db_courses;
    db_courses = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_course = new QSqlQuery(db_courses);
    query_course->prepare("SELECT name, teacher_name, no_credits, optionality, no_hours FROM course");
    query_course->exec();
    modalTable->setQuery(*query_course);
    ui->tableView->setModel(modalTable);
    query_course->prepare("SELECT name from course");
    query_course->exec();
    ui->comboBox->setModel(modalTable);


    QSqlQueryModel* modalList = new QSqlQueryModel();
    QSqlQuery* query_student_courses = new QSqlQuery(db_courses);
   // query_student_courses->prepare("SELECT course.id,student_course.id_course FROM student_course, course WHERE student_course.id_student = '"+id_student_string +"'" "");
//    query_student_courses->prepare("SELECT c.name"
//                                   "FROM student_course sw, course c "
//                                   "WHERE sc.id_student = '"+id_student_string +"' "
//                                   "AND sc.id_course = c.id");
   // query_student_courses->prepare("SELECT course.name FROM course INNER JOIN student_course")

    //query_student_courses->prepare("SELECT name FROM course WHERE course.id IN (SELECT course.id,student_course.id_course FROM student_course sc, course c WHERE sc.id_student = '"+id_student_string +"' AND sc.id_course=c.id_course )");

    //SELECT name FROM public.course WHERE course.id IN (SELECT student_course.id_course FROM public.student_course WHERE student_course.id_student = 8);
    query_student_courses->prepare("SELECT name FROM public.course WHERE course.id IN (SELECT student_course.id_course FROM public.student_course WHERE student_course.id_student = '"+id_student_string+"')");

    query_student_courses->exec();
    modalList->setQuery(*query_student_courses);
    ui->listView->setModel(modalList);
}


void CoursesWidgetStudent::on_pushButton_clicked()
{
    int id_course;
    QString course = ui->comboBox->currentText();

    QSqlQuery query_course_id;
    query_course_id.prepare("SELECT id from course where name = '" + course + "'");
    query_course_id.exec();
    while(query_course_id.next()){
             id_course = query_course_id.value(0).toInt();
    }

    QSqlDatabase db_course;
    db_course = QSqlDatabase::database("QPSQL");
    QSqlQuery query_courses = QSqlQuery(db_course);
    query_courses.prepare("INSERT into student_course ( id_course, id_student )"
                          "VALUES (?,?)");
    query_courses.addBindValue(id_course);
    query_courses.addBindValue(id_student);
    query_courses.exec();


    //query.prepare("INSERT INTO student (first_name, last_name, email, country, study_duration, semester, university_name,  password)"
     //                  "VALUES (?,?,?,?,?,?,?,?)");
}
