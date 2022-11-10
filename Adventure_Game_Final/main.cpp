#include "mainwindow.h"
#include <QFontDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/assets/Planewalker.otf");
    MainWindow w;
    w.show();
    return a.exec();
}
