/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#define RUNNING 1

#include <SFML/Graphics.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <string>

#include "ecs/Ecs.hpp"

namespace rtype
{
    class Client {
      public:
        Client();
        Client(const Client &client);
        void connectToServer(const std::string &ipAdress = "127.0.0.1", const size_t &port = 42069);
        void communicate(boost::asio::ip::udp::socket &socket);
        ~Client() = default;
        int _value;

      protected:
      private:
        std::shared_ptr<std::unordered_map<size_t, std::shared_ptr<ecs::Entity>>> _entities;
        boost::asio::ip::udp::endpoint _receiverEndpoint;
        boost::asio::ip::udp::endpoint _senderEndpoint;
        boost::asio::io_context _ioContext;
        boost::array<char, 128> _sendBuffer;
        boost::array<char, 128> _receiveBuffer;
    };
} // namespace rtype

#endif /* !CLIENT_HPP_ */
