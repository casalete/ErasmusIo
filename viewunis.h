#ifndef VIEWUNIS_H
#define VIEWUNIS_H

#include <QWidget>

#include "universitydialog.h"

namespace Ui {
class ViewUnis;
}

class ViewUnis : public QWidget
{
    Q_OBJECT

public:
    explicit ViewUnis(QWidget *parent = 0);
    ~ViewUnis();

private slots:
    void on_addNewUni_clicked();
    void on_reload_clicked();
    void on_back_clicked();


private:
    Ui::ViewUnis *ui;
    UniversityDialog *unidialog;

};

#endif // VIEWUNIS_H
