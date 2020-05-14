#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "custombutton.h"
#include <QMap>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMap<QString, CustomButton *> _buttonMap;
    QVBoxLayout *_layout;
    QWidget *_mainWidget;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
