/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Click
*/

#ifndef CLICK_HPP_
#define CLICK_HPP_

#include "../components/Clickable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Position.hpp"
#include "ASystem.hpp"
#include "SFML/Graphics.hpp"

namespace ecs
{
    class Click : public ASystem {
      public:
      /**
       * @brief click will set all clickable's states (isHovered, isClicked) depending on mouse position
       * 
       * @param manager shared_ptr to the ecs
       */
        Click(std::shared_ptr<Ecs> &manager);
        ~Click();

        /**
         * @brief check if the mouse is in the hitBox situated at position
         * 
         * @param window window of the scene
         * @param hitBox hitBox of the Clickable entity
         * @param position position of the hitBox
         * @return true if the mouse is in hitBox parameter at position parameter and
         * @return false otherwise
         */
        bool isMouseIn(sf::RenderWindow &window, HitBox &hitBox, Position &position);
        void run(const std::string &sceneName, sf::RenderWindow &window);

      private:
        void hovered(sf::RenderWindow &window, std::shared_ptr<Entity> &entity);
        void clicked(sf::RenderWindow &window, std::shared_ptr<Entity> &entity);
    };
} // namespace ecs

#endif /* !CLICK_HPP_ */
