/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "Client.hpp"
#include "TextureDatabase.hpp"
#include <iostream>

int main(void)
{
    // rtype::TextureDatabase txtDb;

    // txtDb.onCall(0);

    // std::cout << std::endl;

    // txtDb.onCall(1);

    rtype::Client client;

    client.connectToServer();
    return 0;
}
