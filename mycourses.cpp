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

    QSqlDatabase db_courses;
    db_courses = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_myCourses = new QSqlQuery(db_courses);
    query_myCourses->prepare("SELECT name, teacher_name, no_credits, optionality,no_hours FROM course");
    query_myCourses->exec();
    modalTable->setQuery(*query_myCourses);
    ui->tableView->setModel(modalTable);
}

MyCourses::~MyCourses()
{
    delete ui;
}

void MyCourses::on_back_clicked()
{
    hide();
}
