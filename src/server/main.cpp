/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "Server.hpp"

int main(void)
{
    try {
        rtype::Server server;
        server.run();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }
    return 0;
}
