/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "scenes/SceneManager.hpp"

#include "Client.hpp"

int main(void)
{
    rtype::Client client;
    // rtype::SceneManager sceneManager;
    // sceneManager.run();
    client.connectToServer();

    return 0;
}
