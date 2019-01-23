#ifndef DETAILS_H
#define DETAILS_H

#include <QWidget>

namespace Ui {
class Details;
}

class Details : public QWidget
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = 0);
    ~Details();

private:
    Ui::Details *ui;
};

#endif // DETAILS_H
