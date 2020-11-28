#include <QApplication>
#include <QMainWindow>

#include "RealWorld.h"
#include "ui_mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Ui::MainWindow mw;
    QMainWindow q;
    mw.setupUi(&q);
    q.show();
    return a.exec();
}