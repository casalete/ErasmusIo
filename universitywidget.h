#ifndef UNIVERSITYWIDGET_H
#define UNIVERSITYWIDGET_H

#include <QWidget>

namespace Ui {
class UniversityWidget;
}

class UniversityWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UniversityWidget(QWidget *parent = 0);
    ~UniversityWidget();

private slots:
    void on_addUniversity_clicked();


private:
    Ui::UniversityWidget *ui;

    enum Column{
            NAME, COUNTRY,CONTACTPERSONNAME, CONTACTPERSONEMAIL
        };
};

#endif // UNIVERSITYWIDGET_H
