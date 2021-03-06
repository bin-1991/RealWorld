#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QTextEdit>
#include <qscrollarea.h>
#include "ui_mainwindow.h"
//#include "QHexEdit/QHexEdit.h"
#include "HexDump.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* e) override;

private:
    void onOpenFile(const QString& path);

public:

    QDockWidget mDockWidgetOutput;
    QTextEdit* mTextEditOutput;

    QDockWidget mDockWidgetHexDump;
    HexDump* mHexDump;

    QString mFilePath;
    QByteArray mData;
private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();
    void on_actionClose_triggered();

private:
    Ui::MainWindow ui;
};
#endif // MAINWINDOW_H
