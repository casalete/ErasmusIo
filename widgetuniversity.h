#ifndef WIDGETUNIVERSITY_H
#define WIDGETUNIVERSITY_H

#include <QWidget>

namespace Ui {
class WidgetUniversity;
}

class WidgetUniversity : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetUniversity(QWidget *parent = 0);
    ~WidgetUniversity();

private slots:
    void on_addUniversity_clicked();

private:
    Ui::WidgetUniversity *ui;

    enum Column{
        NAME, COUNTRY,CONTACTPERSONNAME, CONTACTPERSONEMAIL
    };

};


#endif // WIDGETUNIVERSITY_H
