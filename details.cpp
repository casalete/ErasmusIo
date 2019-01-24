#include "details.h"
#include "ui_details.h"

Details::Details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
      setWindowTitle("Details");
}

Details::~Details()
{
    delete ui;
}

void Details::on_viewUniversities_clicked()
{
   // hide();
    viewunis = new ViewUnis();
    viewunis->show();

}

void Details::on_back_clicked(){
    hide();
}
