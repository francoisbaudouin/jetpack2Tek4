/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <memory>

#include <boost/thread/thread.hpp>
#include "Communicator.hpp"
#include "ecs/Ecs.hpp"

namespace rtype
{
    class Server {
      public:
        Server();
        ~Server();

        void manageReceiveData();
        void manageSendData();

        void run();
      protected:
      private:
        boost::thread *_communicationThread;
        std::shared_ptr<Communicator> _communicator;
        std::shared_ptr<ecs::Ecs> _ecs;
    };
} // namespace rtype

#endif /* !SERVER_HPP_ */