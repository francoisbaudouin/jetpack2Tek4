/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "scenes/SceneManager.hpp"
#include "Client.hpp"

void connectToServer()
{
    return;
}

int main(void)
{
    // rtype::SceneManager sceneManager;
    // sceneManager.run();
    try {
        rtype::Client client;
        boost::thread *communicationThread = new boost::thread(boost::bind(&rtype::Client::connectToServer, &client));

        communicationThread->join();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
