/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include <boost/asio.hpp>
#include <iostream>
#include <thread>

int main()
{
    boost::asio::io_service io_service;
    // socket creation
    boost::asio::ip::tcp::socket socket(io_service);
    // connection
    socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    // request/message from client
    const std::string msg = "Hello from Client!\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if (!error) {
        std::cout << "Client sent hello message!" << std::endl;
    } else {
        std::cout << "send failed: " << error.message() << std::endl;
    }
    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof) {
        std::cout << "receive failed: " << error.message() << std::endl;
    } else {
        const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
        std::cout << data << std::endl;
    }
    return 0;
}