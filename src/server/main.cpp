/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <boost/thread/thread.hpp>
#include <iostream>

#include "Server.hpp"

#include "Test.hpp"

int main(void)
{
    try {
        rtype::Server server;
        std::shared_ptr<rtype::Server> sharedServer = std::make_shared<rtype::Server>(server);
        boost::thread *communicationThread = new boost::thread(boost::bind(&rtype::Server::run, sharedServer));
        Test test("Bobby", 41);
        Test test1("Mathieu", 6);
        Test test2("Barnabé", 59);

        while (1) {
            sharedServer->lockSendMutex();
            sharedServer->_sendStream.str(std::string());
            sharedServer->_sendStream << test << " " << test1 << " " << test2 << " ";
            sharedServer->unlockSendMutex();
        }

        communicationThread->join();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
