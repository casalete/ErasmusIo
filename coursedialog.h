#ifndef COURSEDIALOG_H
#define COURSEDIALOG_H

#include <QDialog>

namespace Ui {
class CourseDialog;
}

class CourseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CourseDialog(QWidget *parent = 0);
    ~CourseDialog();

    QString course() const;
    QString teacher() const;
    int nrH() const;
    int nrCP() const;
    QString optionality() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CourseDialog *ui;
};

#endif // COURSEDIALOG_H
