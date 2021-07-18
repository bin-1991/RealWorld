#include <QApplication>
#include <QMainWindow>
#include <qtranslator.h>
#include <qfile.h>
#include "RealWorld.h"
#include "mainwindow.h"

void initApp(QApplication& app)
{
    QString LangPath = ":/lang/";
    
    QLocale ql;
    QLocale::Language lang = ql.language();
    switch (lang)
    {
    case QLocale::Chinese:
    {
        LangPath += "zh-cn.qm";
        break;
    }   
    default:
        LangPath += "zh-cn.qm";
        //return;
        break;
    }

    QFont font;
    font.setPointSize(9);
    font.setFamily("微软雅黑");
    app.setFont(font);
    
    app.setWindowIcon(QIcon(":/images/RealWorld.ico"));

    if (QFile(LangPath).exists())
    {
        QTranslator* translator = new QTranslator;
        if (translator->load(LangPath))
        {
            app.installTranslator(translator);
        }
        else
        {
            delete translator;
        }
    }

    return ;
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    initApp(a);

    MainWindow win;
    win.show();
    return a.exec();
}