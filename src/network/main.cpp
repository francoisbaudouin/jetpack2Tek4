/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <ctime>
#include <iostream>
#include <string>
#define ASIO_HAS_BOOST_BIND

#include <asio.hpp>

#include <boost/asio.hpp>
#include <boost/array.hpp>

#define RUNNING 1

std::string make_daytime_string()
{
	std::time_t now = std::time(0);

	return std::ctime(&now);
}

int main()
{
	try {
		boost::asio::io_context io_context;
		boost::asio::ip::udp::socket socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080));
		while (RUNNING) {
			boost::array<char, 1> receiveBuffer;
			boost::asio::ip::udp::endpoint remoteEndpoint;
			socket.receive_from(boost::asio::buffer(receiveBuffer), remoteEndpoint);
			std::string message = make_daytime_string();
			boost::system::error_code ignoredError;
			socket.send_to(boost::asio::buffer(message), remoteEndpoint, 0, ignoredError);
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}

	return 0;
}
