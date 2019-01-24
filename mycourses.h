#ifndef MYCOURSES_H
#define MYCOURSES_H

#include <QWidget>

namespace Ui {
class MyCourses;
}

class MyCourses : public QWidget
{
    Q_OBJECT

public:
    explicit MyCourses(QWidget *parent = 0);
    ~MyCourses();

private:
    Ui::MyCourses *ui;
};

#endif // MYCOURSES_H
