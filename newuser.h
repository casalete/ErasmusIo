#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class NewUser;
}

class NewUser : public QDialog
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = nullptr);
    ~NewUser();

private slots:
    void on_submitButton_clicked();

    void on_studentRadioButton_clicked();

private:
    Ui::NewUser *ui;
};

#endif // NEWUSER_H

