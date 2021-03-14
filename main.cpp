#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont f = a.font();
    f.setPointSize(12);
    a.setFont(f);

    MainWindow w;
    w.show();
    return a.exec();
}
