/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_
#include <SFML/Graphics.hpp>
#include "AComponent.hpp"

namespace ecs
{
    class Drawable : public AComponent {
      public:
        Drawable(const size_t entityId, sf::Texture &texture);
        ~Drawable();

        sf::Sprite &getSprite();
        void setSprite(sf::Sprite sprite);

      protected:
      private:
        sf::Sprite _sprite;
    };
} // namespace ecs

#endif /* !DRAWABLE_HPP_ */
