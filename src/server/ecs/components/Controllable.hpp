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
#include <map>

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
        Controllable(const size_t entityId, const Device::KeyBoardKey &upControll,
            const Device::KeyBoardKey &rightControll, const Device::KeyBoardKey &leftControll,
            const Device::KeyBoardKey &downControll, const Device::KeyBoardKey &fireControll);
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
        std::map<Device::KeyBoardKey, Controlls> _controllMap;
    };
} // namespace ecs

#endif /* !CONTROLLABLE_HPP_ */
