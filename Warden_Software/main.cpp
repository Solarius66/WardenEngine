#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QJsonDocument>

#include "warden_lib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w("save.json");

    w.show();
    return a.exec();
}
