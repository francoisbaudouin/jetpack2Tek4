/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>

#include "Test.hpp"

#define RUNNING 1

int main(void)
{
    try {
        Test test;
        Test test1("Mattéo", 2);
        Test test2("Timothé", 1);
        std::stringstream stringStream;
        boost::asio::io_context io_context;
        boost::asio::ip::udp::socket socket(
            io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 42069));

        stringStream << test;
        stringStream << test1;
        stringStream << test2;
        while (RUNNING) {
            boost::array<char, 1> receiveBuffer;
            boost::asio::ip::udp::endpoint remoteEndpoint;
            socket.receive_from(boost::asio::buffer(receiveBuffer), remoteEndpoint);
            // std::string message = "salut";
            boost::system::error_code ignoredError;
            // std::cout << "ici " << stringStream.str() << std::endl;
            socket.send_to(boost::asio::buffer(stringStream.str()), remoteEndpoint, 0, ignoredError);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    return 0;
}
