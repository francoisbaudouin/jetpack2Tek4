/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Communicator
*/

#ifndef COMMUNICATOR_HPP_
#define COMMUNICATOR_HPP_

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

namespace rtype
{
    class Communicator {
      public:
        /* Member functions */
        /**
         * @brief Constructs a new Communicator object
         *
         * @param port Port of the communicator
         */
        Communicator(const size_t &port = 42069);
        /**
         * @brief Constructs a new Communicator object
         *
         * @param communicator Object form which to construct a new Communicator object
         */
        Communicator(const Communicator &communicator);
        /**
         * @brief Gets the Port object
         *
         * @return An unsigned integer representing the port of the communicator
         */
        size_t getPort() const;
        /**
         * @brief Sets the Port object
         *
         * @param port An unsigned integer representing the port of the communicator
         */
        void setPort(const size_t &port);
        /**
         * @brief Launches the communicator and manage client interactions
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
        /**
         * @brief stop the communication
         *
         */
        void stopCommunication();
        ~Communicator();

        /* Properties */
        std::stringstream _sendStream;
        std::stringstream _receiveStream;

      protected:
      private:
        size_t _port;
        boost::asio::ip::udp::endpoint _remoteEndpoint;
        boost::asio::io_context _ioContext;
        boost::array<char, 128> _receiveBuffer;
        boost::mutex _receiveMutex;
        boost::mutex _sendMutex;
        bool _isRunning;
    };
} // namespace rtype

#endif /* !COMMUNICATOR_HPP_ */
