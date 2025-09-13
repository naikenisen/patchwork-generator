#include <QApplication>
#include <QMainWindow>
#include "ui_mainwindow.h" // généré automatiquement par uic à partir de mainwindow.ui

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    Ui::MainWindow ui;
    ui.setupUi(&window); // initialise la fenêtre avec le contenu du .ui
    window.show();

    return app.exec();
}