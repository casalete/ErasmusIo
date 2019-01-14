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
}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    newuser = new NewUser();
    newuser->show();
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    loginstudent = new LoginStudent();
    loginstudent->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    loginteacher = new LoginTeacher();
    loginteacher->show();
}
