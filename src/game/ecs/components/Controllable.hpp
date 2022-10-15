/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Controllable
*/

#ifndef CONTROLLABLE_HPP_
#define CONTROLLABLE_HPP_

#include "../enums/controlls.hpp"
#include "../enums/event.hpp"
#include "AComponent.hpp"
#include <unordered_map>

namespace ecs
{
    class Controllable : public AComponent {
      public:
        /**
         * @brief Construct a new Controllable component
         *
         * @param entityId related entity id
         * @param upControll pair of Device::KeyBoardKey and Controlls that correspond to the UP controll
         * @param rightControll pair of Device::KeyBoardKey and Controlls that correspond to the RIGHT controll
         * @param leftControll pair of Device::KeyBoardKey and Controlls that correspond to the LEFT controll
         * @param downControll pair of Device::KeyBoardKey and Controlls that correspond to the DOWN controll
         */
        Controllable(const size_t entityId, const std::pair<Device::KeyBoardKey, Controlls> &upControll,
            const std::pair<Device::KeyBoardKey, Controlls> &rightControll,
            const std::pair<Device::KeyBoardKey, Controlls> &leftControll,
            const std::pair<Device::KeyBoardKey, Controlls> &downControll,
            const std::pair<Device::KeyBoardKey, Controlls> &fireControll);
        ~Controllable();

        /**
         * @brief Get the controll associated to the given key
         *
         * @param key : check the control on that key
         * @return Controlls associated to the key given in parameter
         */
        Controlls getAssociatedControll(Device::KeyBoardKey key);

      protected:
      private:
        std::unordered_map<Device::KeyBoardKey, Controlls> _controllMap;
    };
} // namespace ecs

#endif /* !CONTROLLABLE_HPP_ */
