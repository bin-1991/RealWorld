#include "mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
{
    ui.setupUi(this);
    setWindowIcon(QIcon(":/images/RealWorld.ico"));

    dock_widget_output.setWindowTitle(tr("Output"));
    dock_widget_output.setFeatures(QDockWidget::DockWidgetMovable);
    dock_widget_output.setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
    dock_widget_output.setWidget(&text_edit_output);
    addDockWidget(Qt::BottomDockWidgetArea, &dock_widget_output);

    
    dock_widget_hexeditor.setWindowTitle(tr("Hex View"));
    //dock_widget_hexeditor.setWidget(&widget_hexeditor);
    dock_widget_hexeditor.setFeatures(QDockWidget::DockWidgetMovable);
    dock_widget_hexeditor.setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
    dock_widget_hexeditor.setWidget(&hexeditor);
    addDockWidget(Qt::BottomDockWidgetArea, &dock_widget_hexeditor);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_actionOpen_triggered()
{
    file_path = QFileDialog::getOpenFileName(nullptr, tr("Select file"));
    text_edit_output.append(tr("Load file") + ": " + file_path);
}

void MainWindow::on_actionClose_triggered()
{

}
