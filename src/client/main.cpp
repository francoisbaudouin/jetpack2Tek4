/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "Communicator.hpp"
#include "scenes/SceneManager.hpp"

int main(void)
{
    // rtype::SceneManager sceneManager;
    // sceneManager.run();
    try {
        rtype::Communicator communicator;
        boost::thread *communicationThread =
            new boost::thread(boost::bind(&rtype::Communicator::connectToServer, &communicator));

        communicationThread->join();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
