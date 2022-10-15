/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"

using namespace rtype;

Client::Client(const std::string &ipAdress, const size_t &port)
{
	this->_receiverEndpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ipAdress), port);
}

void Client::connectToServer()
{
	boost::asio::ip::udp::socket socket(this->_ioContext);

	socket.open(boost::asio::ip::udp::v4());
	while (RUNNING) {
		socket.send_to(boost::asio::buffer(this->_sendBuffer), this->_receiverEndpoint);
		this->_messageLength = socket.receive_from(boost::asio::buffer(this->_receiveBuffer), this->_senderEndpoint);
		std::cout.write(this->_receiveBuffer.data(), this->_messageLength);
	}
}
