#include "universitydialog.h"
#include "ui_universitydialog.h"

#include "QSql"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

UniversityDialog::UniversityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UniversityDialog)
{
    ui->setupUi(this);
}

UniversityDialog::~UniversityDialog()
{
    delete ui;
}

void UniversityDialog::on_buttonBox_accepted(){
    accept();



}

void UniversityDialog::on_buttonBox_rejected()
{
    reject();
}

void UniversityDialog::on_submit_clicked(){
    //TODO - get values from ui

    QString form_name = ui->lineEdit_name->text();
    QString form_country = ui->lineEdit_country->text();
    QString form_contactName = ui->lineEdit_contactName->text();
    QString form_contactEmail = ui->lineEdit_contactEmail->text();

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("INSERT INTO university (name, country, name_contact_person, email_contact_person)"
               "VALUES (?,?,?,?)");

    query.addBindValue(form_name);
    query.addBindValue(form_country);
    query.addBindValue(form_contactName);
    query.addBindValue(form_contactEmail);
   // query.addBindValue(role);


    query.exec();

    ui->lineEdit_name->clear();
    ui->lineEdit_country->clear();
    ui->lineEdit_contactName->clear();
    ui->lineEdit_contactEmail->clear();

}

void UniversityDialog::on_cancel_clicked(){
    hide();
}



QString UniversityDialog::contactEmail() const{
    return ui->contactEmail->text();
}
QString UniversityDialog::contactName() const{
    return ui->contactName->text();
}
QString UniversityDialog::country() const{
    return ui->country->text();
}
QString UniversityDialog::name() const{
    return ui->name->text();
}


