/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** mainServer
*/

#include <QApplication>
#include "FenServer.h"
#include <QDebug>


int main(int argc, char* argv[])

{
    QApplication app(argc, argv);

    Fenserver windows(4242);

    while (1)
        windows.dataReceve();
    return app.exec();
}
