#include "mainwindow.h"
#include <QFileDialog>
#include <qevent.h>
#include <qurl.h>
#include <qlist.h>
#include <qmimedata.h>

MainWindow::MainWindow(QWidget* parent)
{
    ui.setupUi(this);
    m_dockWidgetOutput.setWindowTitle(tr("Output window"));
    m_dockWidgetOutput.setFeatures(QDockWidget::DockWidgetMovable);
    m_dockWidgetOutput.setWidget(&m_textEditOutput);
    m_textEditOutput.setLineWrapMode(QTextEdit::NoWrap);
    m_textEditOutput.setReadOnly(true);
    addDockWidget(Qt::BottomDockWidgetArea, &m_dockWidgetOutput);

    //m_dockWidgetHexEdit.setWindowTitle(tr("Hex View"));
    //m_dockWidgetHexEdit.setFeatures(QDockWidget::DockWidgetMovable);
    //m_dockWidgetHexEdit.setWidget(&m_hexEditHexView);
    //addDockWidget(Qt::BottomDockWidgetArea, &m_dockWidgetHexEdit);

    //m_hexEditHexView.setOverwriteMode(true);
    
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)

{
    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent* e)
{
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    onOpenFile(fileName);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onOpenFile(const QString& path)
{
    m_textEditOutput.append(tr("Load file") + ":\"" + path + "\"");
    QFile f(path);
    if (f.open(QFile::ReadOnly))
    {
        m_data = f.readAll();
        //m_hexEditHexView.setData(m_data);
    }
    else
    {
        m_textEditOutput.append(tr("Open file") + " \"" + path + "\" failed.");
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("Select file"));
    if (!filePath.isEmpty())
    {
        onOpenFile(filePath);
    }
}

void MainWindow::on_actionClose_triggered()
{

}
