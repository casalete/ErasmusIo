#ifndef DETAILS_H
#define DETAILS_H

#include <QWidget>

#include "viewunis.h"

namespace Ui {
class Details;
}

class Details : public QWidget
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = 0);
    ~Details();

private slots:
    void on_viewUniversities_clicked();
    void on_back_clicked();

private:
    Ui::Details *ui;
    ViewUnis *viewunis;
};

#endif // DETAILS_H