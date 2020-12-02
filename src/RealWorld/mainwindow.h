#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QTextEdit>
#include "ui_mainwindow.h"
#include "hexedit/hexedit.h"

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

    QDockWidget m_dockWidgetOutput;
    QTextEdit m_textEditOutput;

    QDockWidget m_dockWidgetHexEdit;
    HexEdit m_hexEditHexView;

    QString m_filePath;
    QByteArray m_data;
private slots:
    void on_actionOpen_triggered();

    void on_actionClose_triggered();

private:
    Ui::MainWindow ui;
};
#endif // MAINWINDOW_H
