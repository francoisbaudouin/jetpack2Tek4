/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#ifndef CONTROLLABLE_HPP_
#define CONTROLLABLE_HPP_
#include "../enums/event.hpp"
#include "../enums/controlls.hpp"
#include "AComponent.hpp"
#include <unordered_map>

namespace ecs
{
    class Controllable : public AComponent {
      public:
        Controllable(const size_t entityId, std::pair<Device::KeyBoardKey, Controlls> upControll,
            std::pair<Device::KeyBoardKey, Controlls> rightControll,
            std::pair<Device::KeyBoardKey, Controlls> leftControll,
            std::pair<Device::KeyBoardKey, Controlls> downControll);
        ~Controllable();

        Controlls getAssociatedControll(Device::KeyBoardKey key);

      protected:
      private:
        std::unordered_map<Device::KeyBoardKey, Controlls> _controllMap;
    };
} // namespace ecs

#endif /* !CONTROLLABLE_HPP_ */
