/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** mainClient
*/

#include <QApplication>
#include "FenClient.h"

int main(int argc, char* argv[])
{
    FenClient my_client;

    my_client.onConnexion("127.0.0.1", 4242);
    my_client.sendMessage("yo");

    return 0;
}
