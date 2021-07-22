#include "mainwindow.h"
#include <QFileDialog>
#include <qevent.h>
#include <qurl.h>
#include <qlist.h>
#include <qmimedata.h>

MainWindow::MainWindow(QWidget* parent)
{
    ui.setupUi(this);

    mTextEditOutput = new QTextEdit(this);
    mTextEditOutput->setLineWrapMode(QTextEdit::NoWrap);
    mTextEditOutput->setReadOnly(true);

    mDockWidgetOutput.setWindowTitle(tr("Output window"));
    mDockWidgetOutput.setFeatures(QDockWidget::DockWidgetMovable);
    mDockWidgetOutput.setWidget(mTextEditOutput);
    addDockWidget(Qt::BottomDockWidgetArea, &mDockWidgetOutput);

    mHexDump = new HexDump(this);
    mDockWidgetHexDump.setWindowTitle(tr("Hex View"));
    mDockWidgetHexDump.setFeatures(QDockWidget::DockWidgetMovable);
    mDockWidgetHexDump.setWidget(mHexDump);
    //QSizePolicy p;
    //p.setVerticalPolicy(QSizePolicy::Preferred);
    //mDockWidgetHexDump.setSizePolicy(p);
    
    addDockWidget(Qt::TopDockWidgetArea, &mDockWidgetHexDump);

    //mHexDump->setOverwriteMode(true);
    
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
    mTextEditOutput->append(tr("Load file") + ":\"" + path + "\"");
    QFile f(path);
    if (f.open(QFile::ReadOnly))
    {
        mData = f.readAll();
        //m_hexEditHexView.setData(m_data);
    }
    else
    {
        mTextEditOutput->append(tr("Open file") + " \"" + path + "\" failed.");
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

void MainWindow::on_actionExit_triggered()
{
    delete mHexDump;
    delete mTextEditOutput;
    close();
}

