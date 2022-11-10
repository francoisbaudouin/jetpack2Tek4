/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <boost/thread/thread.hpp>
#include <iostream>
#include <memory>

#include "Communicator.hpp"

#include "Test.hpp"

int main(void)
{
    try {
        rtype::Communicator communicator;
        std::shared_ptr<rtype::Communicator> sharedCommunicator = std::make_shared<rtype::Communicator>(communicator);
        boost::thread *communicationThread = new boost::thread(boost::bind(&rtype::Communicator::run, sharedCommunicator));
        Test *test = new Test("Bobby", 41);
        Test test1("Mathieu", 6);
        Test test2("Barnabé", 59);
        void *tmp = malloc(sizeof(Test));
        tmp = memcpy(tmp, test, sizeof(Test));
        Test *test3 = new Test;
        std::string st;
        std::stringstream stream;

        test3 = reinterpret_cast<Test *>(tmp);
        std::cout << "name: " << test3->_name << " value: " << test3->_value << " adress: " << test3 << std::endl;
        // void *tmp1 = malloc(sizeof(Test));
        // tmp1 = memcpy(tmp, test1, sizeof(Test));
        // void *tmp2 = malloc(sizeof(Test));
        // tmp2 = memcpy(tmp, test2, sizeof(Test));

        while (1) {
            // sharedCommunicator->lockSendMutex();
            sharedCommunicator->_sendStream.str(std::string());
            sharedCommunicator->_sendStream << tmp << " "/*  << tmp1 << " " << tmp2 << " " */;
            // sharedCommunicator->unlockSendMutex();
            sharedCommunicator->lockReceiveMutex();
            std::cout << "in\n";
            // std::cout << sharedCommunicator->_receiveStream.str() << std::endl;
            st = sharedCommunicator->_receiveStream.str();
            // stream << sharedCommunicator->_receiveStream.rdbuf();
            // stream >> st;
            std::cout << st << std::endl;
            // sharedCommunicator->_receiveStream.str(std::string());
            sharedCommunicator->unlockReceiveMutex();
        }

        communicationThread->join();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}
