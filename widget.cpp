#include "widget.h"
#include "ui_widget.h"
#include "coursedialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList labels;
    setWindowTitle("Courses");
    ui->tableWidget->setColumnCount(3);
    labels << "COURSE" << "TEACHER" << "NUMBER OF HOURS";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addCourse_clicked()
{
    int res, nrHours, counter;
    QString courseName, teacherName;
    CourseDialog cd(this);
    cd.setWindowTitle("Add Course");
    res = cd.exec();
    if (res == QDialog::Rejected)
        return;
    courseName = cd.course();
    teacherName = cd.teacher();
    nrHours = cd.nrH();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    counter = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(counter, COURSE, new QTableWidgetItem(courseName));
    ui->tableWidget->setItem(counter, TEACHER, new QTableWidgetItem(teacherName));
    ui->tableWidget->setItem(counter, NROFHOURS, new QTableWidgetItem(QString::number(nrHours)));

}
