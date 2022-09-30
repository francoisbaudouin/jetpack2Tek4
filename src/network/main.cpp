/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#include <ctime>
#include <iostream>
#include <string>
#include <asio.hpp>

std::string make_daytime_string()
{
	using namespace std;
	time_t now = time(0);
	return ctime(&now);
}

int main(void)
{
	try {
		asio::io_context io_context;
		asio::ip::tcp::acceptor acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 8080));
		for (;;) {
			asio::ip::tcp::socket socket(io_context);
			acceptor.accept(socket);
			std::string message = make_daytime_string();

			asio::error_code ignored_error;
			asio::write(socket, asio::buffer(message), ignored_error);
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
