/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#define RUNNING 1

#include <boost/asio.hpp>
#include <iostream>
#include <boost/array.hpp>

int main(int ac, char **av)
{
	try {
		boost::array<char, 1> sendBuffer = {{0}};
		boost::array<char, 128> receiveBuffer;
		boost::asio::io_context ioContext;
		boost::asio::ip::udp::resolver resolver(ioContext);
		boost::asio::ip::udp::endpoint receiverEndpoint;
		boost::asio::ip::udp::socket socket(ioContext);
		boost::asio::ip::udp::endpoint senderEndpoint;
		size_t len;

		if (ac != 2) {
			std::cerr << "Usage: client <host>" << std::endl;
			return 84;
		}

		receiverEndpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(av[1]), 8080);
		socket.open(boost::asio::ip::udp::v4());
		while (RUNNING) {
			socket.send_to(boost::asio::buffer(sendBuffer), receiverEndpoint);
			len = socket.receive_from(boost::asio::buffer(receiveBuffer), senderEndpoint);
			std::cout.write(receiveBuffer.data(), len);
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}

	return 0;
}
