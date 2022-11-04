/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include "Client.hpp"
#include <boost/thread/thread.hpp>

void communicate(rtype::Client *client)
{
    // client->connectToServer();
    client->_value ++;

    return;
}

int main(void)
{
    rtype::Client client;
    // rtype::Client *client = new rtype::Client();
    std::cout << "before thread: " << client._value << std::endl;
    boost::thread communicator(communicate, &client);
    // boost::thread communicator(std::bind(&rtype::Client::connectToServer, client));
    communicator.join();
    std::cout << "after thread: " << client._value << std::endl;

    return 0;
}
