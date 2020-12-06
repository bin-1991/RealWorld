#include "mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
{
    ui.setupUi(this);
    setWindowIcon(QIcon(":/images/RealWorld.ico"));

    m_dockWidgetOutput.setWindowTitle(tr("Output window"));
    m_dockWidgetOutput.setFeatures(QDockWidget::DockWidgetMovable);
    m_dockWidgetOutput.setWidget(&m_textEditOutput);
    m_textEditOutput.setLineWrapMode(QTextEdit::NoWrap);
    m_textEditOutput.setReadOnly(true);
    addDockWidget(Qt::BottomDockWidgetArea, &m_dockWidgetOutput);

    m_dockWidgetHexEdit.setWindowTitle(tr("Hex View"));
    m_dockWidgetHexEdit.setFeatures(QDockWidget::DockWidgetMovable);
    m_dockWidgetHexEdit.setWidget(&m_hexEditHexView);
    addDockWidget(Qt::BottomDockWidgetArea, &m_dockWidgetHexEdit);

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_actionOpen_triggered()
{
    m_filePath = QFileDialog::getOpenFileName(nullptr, tr("Select file"));
    m_textEditOutput.append(tr("Load file") + ": " + m_filePath);
    QFile f(m_filePath);
    if (f.isReadable())
    {
        m_data = f.readAll();
    }
    else
    {
        m_textEditOutput.append(tr("Open file") + " \"" + m_filePath + "\" failed.");
    }

}

void MainWindow::on_actionClose_triggered()
{

}
