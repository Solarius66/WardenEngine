#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "savebutton.h"
#include "buildbutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _layout  = new QVBoxLayout(this);
    _buttonMap.insert("Build", new BuildButton(this));
    _buttonMap.insert("Save", new SaveButton(this));
    _layout->addWidget(_buttonMap["Build"]);
    _layout->addWidget(_buttonMap["Save"]);
    _mainWidget = new QWidget(this);
    _mainWidget->setLayout(_layout);
    setCentralWidget(_mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
