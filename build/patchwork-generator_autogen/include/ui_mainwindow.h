/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsave;
    QAction *actionexport_to_jpeg;
    QAction *actionpdf;
    QAction *actionpng;
    QAction *actionsave_2;
    QAction *actionsave_as;
    QAction *actionundo;
    QAction *actionredo;
    QAction *actionremove_all_figures;
    QAction *actionselect_all_figures;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPlainTextEdit *title;
    QPlainTextEdit *subtitle;
    QLabel *title_label;
    QLabel *subtitle_label;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuPatchwork;
    QMenu *menuexport;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1409, 991);
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionexport_to_jpeg = new QAction(MainWindow);
        actionexport_to_jpeg->setObjectName(QString::fromUtf8("actionexport_to_jpeg"));
        actionpdf = new QAction(MainWindow);
        actionpdf->setObjectName(QString::fromUtf8("actionpdf"));
        actionpng = new QAction(MainWindow);
        actionpng->setObjectName(QString::fromUtf8("actionpng"));
        actionsave_2 = new QAction(MainWindow);
        actionsave_2->setObjectName(QString::fromUtf8("actionsave_2"));
        actionsave_as = new QAction(MainWindow);
        actionsave_as->setObjectName(QString::fromUtf8("actionsave_as"));
        actionundo = new QAction(MainWindow);
        actionundo->setObjectName(QString::fromUtf8("actionundo"));
        actionredo = new QAction(MainWindow);
        actionredo->setObjectName(QString::fromUtf8("actionredo"));
        actionremove_all_figures = new QAction(MainWindow);
        actionremove_all_figures->setObjectName(QString::fromUtf8("actionremove_all_figures"));
        actionselect_all_figures = new QAction(MainWindow);
        actionselect_all_figures->setObjectName(QString::fromUtf8("actionselect_all_figures"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 60, 1011, 791));
        title = new QPlainTextEdit(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(1060, 190, 281, 121));
        subtitle = new QPlainTextEdit(centralwidget);
        subtitle->setObjectName(QString::fromUtf8("subtitle"));
        subtitle->setGeometry(QRect(1060, 380, 281, 471));
        title_label = new QLabel(centralwidget);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(1150, 140, 71, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Noto Rashi Hebrew"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        title_label->setFont(font1);
        subtitle_label = new QLabel(centralwidget);
        subtitle_label->setObjectName(QString::fromUtf8("subtitle_label"));
        subtitle_label->setGeometry(QRect(1140, 330, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Clear Sans Light"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        subtitle_label->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1409, 28));
        menuPatchwork = new QMenu(menubar);
        menuPatchwork->setObjectName(QString::fromUtf8("menuPatchwork"));
        menuexport = new QMenu(menuPatchwork);
        menuexport->setObjectName(QString::fromUtf8("menuexport"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuPatchwork->menuAction());
        menuPatchwork->addAction(menuexport->menuAction());
        menuexport->addAction(actionpdf);
        menuexport->addAction(actionpng);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        actionexport_to_jpeg->setText(QCoreApplication::translate("MainWindow", "export to jpeg", nullptr));
        actionpdf->setText(QCoreApplication::translate("MainWindow", "pdf", nullptr));
        actionpng->setText(QCoreApplication::translate("MainWindow", "png", nullptr));
        actionsave_2->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        actionsave_as->setText(QCoreApplication::translate("MainWindow", "save as", nullptr));
        actionundo->setText(QCoreApplication::translate("MainWindow", "undo", nullptr));
        actionredo->setText(QCoreApplication::translate("MainWindow", "redo", nullptr));
        actionremove_all_figures->setText(QCoreApplication::translate("MainWindow", "remove selected figure", nullptr));
        actionselect_all_figures->setText(QCoreApplication::translate("MainWindow", "select all figures", nullptr));
        title_label->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        subtitle_label->setText(QCoreApplication::translate("MainWindow", "Subtitle", nullptr));
        menuPatchwork->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
        menuexport->setTitle(QCoreApplication::translate("MainWindow", "export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
