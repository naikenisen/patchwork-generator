#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class PatchworkView;
class QPlainTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PatchworkView *patchworkView;
    QPlainTextEdit *titleEdit;
    QPlainTextEdit *subtitleEdit;
    // Ui::MainWindow *ui; // Not used
};

#endif // MAINWINDOW_H