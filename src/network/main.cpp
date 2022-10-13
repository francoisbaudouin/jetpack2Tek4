/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#define RUNNING 1

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include "initialization/Loadconfig.hpp"

std::string make_daytime_string()
{
    std::time_t now = std::time(0);

    return std::ctime(&now);
}

int main()
{
    // initialization::Loadconfig congfig;

    initialization::Loadconfig test;
    try {
        boost::array<char, 1> receiveBuffer;
        boost::asio::io_context ioContext;
        boost::asio::ip::udp::endpoint remoteEndpoint;
        boost::asio::ip::udp::socket socket(
            ioContext, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080));
        boost::system::error_code ignoredError;
        std::string message;

        while (RUNNING) {
            socket.receive_from(boost::asio::buffer(receiveBuffer), remoteEndpoint);
            message = make_daytime_string();
            socket.send_to(boost::asio::buffer(message), remoteEndpoint, 0, ignoredError);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    return 0;
}

/* std::string read_(boost::asio::ip::tcp::socket & socket) {
       boost::asio::streambuf buf;
       boost::asio::read_until( socket, buf, "\n" );
       std::string data = boost::asio::buffer_cast<const char*>(buf.data());
       return data;
}
void send_(boost::asio::ip::tcp::socket & socket, const std::string& message) {
       const std::string msg = message + "\n";
       boost::asio::write( socket, boost::asio::buffer(message) );
}

int main(void)
{
    boost::asio::io_service io_service;
    // listen for new connection
    boost::asio::ip::tcp::acceptor acceptor_(
        io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234));
    // socket creation
    boost::asio::ip::tcp::socket socket_(io_service);
    // waiting for connection
    acceptor_.accept(socket_);
    // read operation
    std::string message = read_(socket_);
    std::cout << message << std::endl;
    // write operation
    send_(socket_, "Hello From Server!");
    std::cout << "Servent sent Hello message to Client!" << std::endl;
    return 0;
} */
