#include <QApplication>
#include <QMainWindow>
#include <qtranslator.h>
#include <qfile.h>
#include "RealWorld.h"
#include "mainwindow.h"

void loadTranstor(const QApplication& app)
{
    QString lang_dir = app.applicationDirPath() + "/lang/";
    
    QLocale ql;
    const char* lang_file = NULL;
    QLocale::Language lang = ql.language();
    switch (lang)
    {
    case QLocale::Chinese:
        lang_file = "zh-cn.qm";
        break;
    default:
        lang_file = NULL;
    }

    if (lang_file)
    {
        QFile f(lang_dir + lang_file);
        if (f.exists())
        {
            QTranslator* translator = new QTranslator;
            translator->load(lang_file);
            app.installTranslator(translator);
        }
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