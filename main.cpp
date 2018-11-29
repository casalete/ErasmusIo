#include "mainwindow.h"
#include <QApplication>
#include "loginstudent.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    LogInStudent n;
    n.show();
    return a.exec();
}
