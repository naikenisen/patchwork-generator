
#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    patchworkView = new PatchworkView(this);
    patchworkView->setMinimumSize(1010, 790);
    layout->addWidget(patchworkView);

    titleEdit = new QPlainTextEdit(this);
    titleEdit->setPlaceholderText("Enter title here...");
    layout->addWidget(titleEdit);

    subtitleEdit = new QPlainTextEdit(this);
    subtitleEdit->setPlaceholderText("Enter subtitle here...");
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