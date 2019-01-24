#include "viewunis.h"
#include "ui_viewunis.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

ViewUnis::ViewUnis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewUnis)
{
    ui->setupUi(this);
      setWindowTitle("View Universities");

      QSqlDatabase db_universities;
      db_universities = QSqlDatabase::database("QPSQL");
      QSqlQueryModel* modalTable = new QSqlQueryModel();
      QSqlQuery* query_university = new QSqlQuery(db_universities);
      query_university->prepare("SELECT name, country, name_contact_person, email_contact_person FROM university");
      query_university->exec();
      modalTable->setQuery(*query_university);
      ui->tableView->setModel(modalTable);

}

ViewUnis::~ViewUnis()
{
    delete ui;
}

void ViewUnis::on_addNewUni_clicked(){

    unidialog = new UniversityDialog;
    unidialog->show();

}

void ViewUnis::on_reload_clicked(){

    ui->tableView->close();

    QSqlDatabase db_universities;
    db_universities = QSqlDatabase::database("QPSQL");
    QSqlQueryModel* modalTable = new QSqlQueryModel();
    QSqlQuery* query_university = new QSqlQuery(db_universities);
    query_university->prepare("SELECT name, country, name_contact_person, email_contact_person FROM university");
    query_university->exec();
    modalTable->setQuery(*query_university);
    ui->tableView->setModel(modalTable);

    ui->tableView->show();
}

void ViewUnis::on_back_clicked()
{
    hide();
}

