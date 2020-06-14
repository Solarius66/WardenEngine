/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** mainClient
*/

#include <QApplication>
#include "FenClient.h"

int main()
{
    FenClient my_client;

    my_client.onConnexion("localhost", 4242);

    my_client.sendMessage("yo");
    return 0;
}
