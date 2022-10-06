/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#define RUNNING 1

int main(int ac, char **av)
{
	try {
		boost::array<char, 1> sendBuf = {{0}};
		boost::array<char, 128> recvBuf;
		boost::asio::io_context ioContext;
		boost::asio::ip::udp::resolver resolver(ioContext);
		boost::asio::ip::udp::endpoint receiverEndpoint(boost::asio::ip::address::from_string(av[1]), 8080);
		boost::asio::ip::udp::socket socket(ioContext);
		boost::asio::ip::udp::endpoint senderEndpoint;
		size_t len;

		if (ac != 2) {
			std::cerr << "Usage: client <host>" << std::endl;
			return 84;
		}

		socket.open(boost::asio::ip::udp::v4());
		while (RUNNING) {
			socket.send_to(boost::asio::buffer(sendBuf), receiverEndpoint);
			len = socket.receive_from(boost::asio::buffer(recvBuf), senderEndpoint);
			std::cout.write(recvBuf.data(), len);
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}

	return 0;
}