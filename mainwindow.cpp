#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    openConnection();
}

void MainWindow::on_studentButton_clicked()
{
    hide();
    loginstudent = new LoginStudent();
    loginstudent->show();
}

void MainWindow::on_teacherButton_clicked()
{
    hide();
    loginteacher = new LoginTeacher();
    loginteacher->show();
}
