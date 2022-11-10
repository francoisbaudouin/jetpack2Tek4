/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#define RUNNING 1

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

namespace rtype
{
    class Server {
      public:
        /* Member functions */
        /**
         * @brief Constructs a new Server object
         *
         * @param port Port of the server
         */
        Server(const size_t &port = 42069);
        /**
         * @brief Constructs a new Server object
         *
         * @param server Object form which to construct a new Server object
         */
        Server(const Server &server);
        /**
         * @brief Gets the Port object
         *
         * @return An unsigned integer representing the port of the server
         */
        size_t getPort() const;
        /**
         * @brief Sets the Port object
         *
         * @param port An unsigned integer representing the port of the server
         */
        void setPort(const size_t &port);
        /**
         * @brief Launches the server and manage client interactions
         *
         */
        void run();
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
        ~Server();

        /* Properties */
        std::stringstream _sendStream;

      protected:
      private:
        size_t _port;
        boost::asio::ip::udp::endpoint _remoteEndpoint;
        boost::asio::io_context _ioContext;
        boost::array<char, 128> _receiveBuffer;
        std::stringstream _receiveStream;
        boost::mutex _receiveMutex;
        boost::mutex _sendMutex;
    };
} // namespace rtype

#endif /* !SERVER_HPP_ */
