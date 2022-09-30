/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <iostream>
#include <boost/array.hpp>
#include <asio.hpp>

using asio::ip::tcp;

int main(int ac, char **av)
{
	try {
		if (ac != 2) {
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}
		asio::io_context io_context;
		tcp::resolver resolver(io_context);
		tcp::resolver::results_type endpoints = resolver.resolve(av[1], "daytime");
		tcp::socket socket(io_context);
		asio::connect(socket, endpoints);
		for (;;) {
			boost::array<char, 128> buf;
			asio::error_code error;

			size_t len = socket.read_some(asio::buffer(buf), error);
			if (error == asio::error::eof)
				break;
			else if (error)
				throw asio::system_error(error);

			std::cout.write(buf.data(), len);
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
