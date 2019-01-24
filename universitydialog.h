#ifndef UNIVERSITYDIALOG_H
#define UNIVERSITYDIALOG_H

#include <QWidget>
#include <QDialog>

#include "universitydialog.h"

namespace Ui {
class UniversityDialog;
}

class UniversityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UniversityDialog(QWidget *parent = 0);
    ~UniversityDialog();

    QString name() const;
    QString country() const;
    QString contactName() const;
    QString contactEmail() const;



private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_submit_clicked();

    void on_cancel_clicked();

private:
    Ui::UniversityDialog *ui;
};

#endif // UNIVERSITYDIALOG_H
