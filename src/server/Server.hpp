/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <memory>

#include "Communicator.hpp"
#include "ecs/Ecs.hpp"

namespace rtype
{
    class Server {
      public:
        Server(std::shared_ptr<Communicator> communicator, std::shared_ptr<ecs::Ecs> ecs);
        void manageReceiveData();
        void run();
        ~Server();

      protected:
      private:
        std::shared_ptr<Communicator> _communicator;
        std::shared_ptr<ecs::Ecs> _ecs;
    };
} // namespace rtype

#endif /* !SERVER_HPP_ */
