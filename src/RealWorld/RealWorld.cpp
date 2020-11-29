#include <QApplication>
#include <QMainWindow>

#include "RealWorld.h"
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow win;
    win.show();
    return a.exec();
}