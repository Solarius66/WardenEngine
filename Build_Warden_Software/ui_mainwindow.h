/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *TreeView;
    QWidget *Editor;
    QWidget *Inspector;
    QWidget *command;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(852, 600);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TreeView = new QWidget(centralwidget);
        TreeView->setObjectName(QStringLiteral("TreeView"));
        TreeView->setGeometry(QRect(10, 10, 120, 551));
        Editor = new QWidget(centralwidget);
        Editor->setObjectName(QStringLiteral("Editor"));
        Editor->setGeometry(QRect(140, 10, 541, 341));
        Editor->setStyleSheet(QStringLiteral(""));
        Inspector = new QWidget(centralwidget);
        Inspector->setObjectName(QStringLiteral("Inspector"));
        Inspector->setGeometry(QRect(710, 20, 120, 541));
        command = new QWidget(centralwidget);
        command->setObjectName(QStringLiteral("command"));
        command->setGeometry(QRect(140, 360, 541, 201));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 852, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        TreeView->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
