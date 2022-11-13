/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "Communicator.hpp"
#include "scenes/SceneManager.hpp"
#include "SFML/Audio.hpp"

int main(void)
{
    try {
        rtype::SceneManager sceneManager;
        sceneManager.run();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
