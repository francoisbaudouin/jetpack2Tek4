/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <boost/thread/thread.hpp>
#include <iostream>

#include "Communicator.hpp"
#include "Server.hpp"
#include "ecs/Ecs.hpp"

#include "Test.hpp"

int main(void)
{
    try {
        ecs::Ecs ecs;
        std::shared_ptr<ecs::Ecs> sharedEcs = std::make_shared<ecs::Ecs>(ecs);
        rtype::Communicator communicator;
        std::shared_ptr<rtype::Communicator> sharedCommunicator = std::make_shared<rtype::Communicator>(communicator);
        rtype::Server server(sharedCommunicator, sharedEcs);
        boost::thread *communicationThread = new boost::thread(boost::bind(&rtype::Communicator::run, sharedCommunicator));

        server.run();
        communicationThread->join();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
