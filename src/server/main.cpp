/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <boost/thread/thread.hpp>
#include <iostream>

#include "Communicator.hpp"

#include "Test.hpp"

int main(void)
{
    try {
        rtype::Communicator communicator;
        std::shared_ptr<rtype::Communicator> sharedServer = std::make_shared<rtype::Communicator>(communicator);
        boost::thread *communicationThread = new boost::thread(boost::bind(&rtype::Communicator::run, sharedServer));
        // Test test("Bobby", 41);
        // Test test1("Mathieu", 6);
        // Test test2("Barnabé", 59);

        while (1) {
            sharedServer->lockSendMutex();
            //sharedServer->_sendStream.str(std::string());
            //sharedServer->_sendStream << test << " " << test1 << " " << test2 << " ";
            sharedServer->unlockSendMutex();
            sharedServer->lockReceiveMutex();
            std::cout << sharedServer->_receiveStream.str() << std::endl;
            sharedServer->unlockReceiveMutex();    
        }
        communicationThread->join();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
