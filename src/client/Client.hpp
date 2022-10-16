/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#define RUNNING 1

#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "ecs/Ecs.hpp"

namespace rtype {
	class Client {
		public:
			Client(const std::string &ipAdress = "127.0.0.1", const size_t &port = 42069);
			void connectToServer();
			void run(boost::asio::ip::udp::socket &socket);
			~Client() = default;

		protected:
		private:
			boost::array<char, 128> _sendBuffer;
			boost::array<char, 128> _receiveBuffer;
			boost::asio::io_context _ioContext;
			boost::asio::ip::udp::endpoint _receiverEndpoint;
			boost::asio::ip::udp::endpoint _senderEndpoint;
			size_t _messageLength;
			std::shared_ptr<ecs::Ecs> _sharedEcs;
			sf::RenderWindow _window;
	};
}

#endif /* !CLIENT_HPP_ */
