#include "mainwindow.h"
#include "patchworkview.h"
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1400, 1000);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    titleEdit = new QPlainTextEdit(this);
    titleEdit->setPlaceholderText("Enter title here...");
    subtitleEdit = new QPlainTextEdit(this);
    subtitleEdit->setPlaceholderText("Enter subtitle here...");
    patchworkView = new PatchworkView(this, titleEdit, subtitleEdit);
    patchworkView->setMinimumSize(1010, 790);
    layout->addWidget(patchworkView);
    layout->addWidget(titleEdit);
    layout->addWidget(subtitleEdit);

    // Menu
    QMenu *fileMenu = menuBar()->addMenu("File");
    QMenu *exportMenu = fileMenu->addMenu("Export");

    QAction *pdfAction = exportMenu->addAction("Export PDF");
    QAction *pngAction = exportMenu->addAction("Export PNG");

    connect(pdfAction, &QAction::triggered, patchworkView, &PatchworkView::exportPDF);
    connect(pngAction, &QAction::triggered, patchworkView, &PatchworkView::exportPNG);
}

MainWindow::~MainWindow() {}