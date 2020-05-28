#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMap>
#include <QVBoxLayout>
#include <QPushButton>

#include "warden_lib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMap<QString, QPushButton *> _buttonMap;
    QVBoxLayout *_layout;
    QWidget *_mainWidget;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
