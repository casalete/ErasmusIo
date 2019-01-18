#include "universitydialog.h"
#include "ui_universitydialog.h"

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
    QDialog::accept();
}

void UniversityDialog::on_buttonBox_rejected()
{
    QDialog::reject();
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


