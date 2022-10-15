/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/
#define RUNNING 1

#include "client/Client.hpp"

#include <boost/asio.hpp>
#include <iostream>
#include <boost/array.hpp>

int main(void)
{
	try {
		rtype::Client client;
		client.connectToServer();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}

	return 0;
}
