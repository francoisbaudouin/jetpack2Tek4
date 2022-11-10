/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#define RUNNING 1

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>

namespace rtype
{
    class Client {
      public:
        /* Member functions */
        /**
         * @brief Constructs a new Client object
         *
         * @param ipAdress ipAdress of the server
         * @param port port of the server
         */
        Client(const std::string &ipAdress = "127.0.0.1", const size_t &port = 42069);
        /**
         * @brief Constructs a new Client object
         *
         * @param client object from which to construct a new Client object
         */
        Client(const Client &client);
        /**
         * @brief Gets the Ip Adress object
         *
         * @return std::string string corresponding to the ipAdress of the server
         */
        std::string getIpAdress() const;
        /**
         * @brief Gets the Port object
         *
         * @return size_t port of the server
         */
        size_t getPort() const;
        /**
         * @brief Sets the Ip Adress object
         *
         * @param ipAdress ipAdress of the server
         */
        void setIpAdress(const std::string &ipAdress);
        /**
         * @brief Sets the Port object
         *
         * @param port port of the server
         */
        void setPort(const size_t &port);
        /**
         * @brief Connects to the server using an ipAdress and a port given as parameter during the client construction
         *
         */
        void connectToServer();
        /**
         * @brief Initiates and maintains a communication between the client and the server
         *
         * @param socket Socket of the server
         */
        void communicate(boost::asio::ip::udp::socket &socket);
        /**
         * @brief Locks the mutex for sending process
         *
         */
        void lockSendMutex();
        /**
         * @brief Unlocks the mutex for sending process
         *
         */
        void unlockSendMutex();
        /**
         * @brief Locks the mutex for receiving process
         *
         */
        void lockReceiveMutex();
        /**
         * @brief Unlocks the mutex for receiving process
         *
         */
        void unlockReceiveMutex();
        ~Client() = default;

        /* Properties */
        std::stringstream _sendStream;

      protected:
      private:
        std::string _ipAdress;
        size_t _port;
        boost::asio::ip::udp::endpoint _receiverEndpoint;
        boost::asio::ip::udp::endpoint _senderEndpoint;
        boost::asio::io_context _ioContext;
        boost::array<char, 128> _receiveBuffer;
        std::stringstream _receiveStream;
        boost::mutex _sendMutex;
        boost::mutex _receiveMutex;
    };
} // namespace rtype

#endif /* !CLIENT_HPP_ */
