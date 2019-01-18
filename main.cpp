#include <QApplication>
#include "widget.h"
#include "loginstudent.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow mainWindow;
    //mainWindow.setStyleSheet("background-image:url(:maini.jpg)");
       mainWindow.show();

    return a.exec();
}
