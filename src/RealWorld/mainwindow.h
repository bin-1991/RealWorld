#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdockwidget.h>
#include <qtextedit.h>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
public:

    QDockWidget dock_widget_output;
    QTextEdit text_edit_output;

    QString file_path;
private slots:
    void on_actionOpen_triggered();

    void on_actionClose_triggered();

private:
    Ui::MainWindow ui;
};
#endif // MAINWINDOW_H
