/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <boost/thread/thread.hpp>

#include "Client.hpp"

void communicate(rtype::Client *client)
{
    client->connectToServer();

    return;
}

int main(void)
{
    rtype::Client client;
    boost::thread communicator(communicate, &client);

    communicator.join();

    return 0;
}
