#include <QApplication>
#include <QMainWindow>
#include <qtranslator.h>
#include <qfile.h>
#include "RealWorld.h"
#include "mainwindow.h"

void loadTranstor(const QApplication& app)
{
    QString LangPath = app.applicationDirPath() + "/lang/";
    
    QLocale ql;
    QLocale::Language lang = ql.language();
    switch (lang)
    {
    case QLocale::Chinese:
        LangPath += "zh-cn.qm";
        break;
    default:
        LangPath += "zh-cn.qm";
        return;
    }

    if (QFile(LangPath).exists())
    {
        QTranslator* translator = new QTranslator;
        translator->load(LangPath);
        app.installTranslator(translator);
    }

    return;
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    loadTranstor(a);

    MainWindow win;
    win.show();
    return a.exec();
}