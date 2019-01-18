#include "universitywidget.h"
#include "ui_universitywidget.h"

UniversityWidget::UniversityWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UniversityWidget)
{
    ui->setupUi(this);
    QStringList labels;
    setWindowTitle("Universities");
        ui->tableWidget->setColumnCount(4);
        labels << "NAME" << "COUNTRY" << "CONTACT PERSON NAME"<<"CONTACT PERSON EMAIL";
        ui->tableWidget->setHorizontalHeaderLabels(labels);
}

UniversityWidget::~UniversityWidget()
{
    delete ui;
}

void UniversityWidget::on_addUniversity_clicked()
{
    int res, counter;
    QString name, country, contactName, contactEmail ;

    UniversityDialog cd(this);
    cd.setWindowTitle("Add University");
    res = cd.exec();
    if (res == QDialog::Rejected)
        return;

    name = cd.name();
    country = cd.country();
    contactName = cd.contactName();
    contactEmail = cd.contactEmail();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    counter = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(counter, NAME, new QTableWidgetItem(name));
    ui->tableWidget->setItem(counter, COUNTRY, new QTableWidgetItem(country));
    ui->tableWidget->setItem(counter, CONTACTPERSONNAME, new QTableWidgetItem(contactName));
    ui->tableWidget->setItem(counter, CONTACTPERSONEMAIL, new QTableWidgetItem(contactEmail));

}
