/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** mainServer
*/

#include <QApplication>
#include "FenServer.h"


int main(int argc, char* argv[])

{
    QApplication app(argc, argv);

    Fenserver windows(4242);
    windows.show();

    return app.exec();
}