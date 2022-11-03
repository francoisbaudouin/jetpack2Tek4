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
        /**
         * @brief Construct a new Drawable component
         *
         * @param entityId : related entity id
         * @param texture : wanted texture for the drawable entity
         */
        Drawable(const size_t entityId, const sf::Texture &texture);

        ~Drawable();

        /**
         * @brief Get the entity Sprite
         *
         * @return reference to the sf::Sprite of the entity
         */
        sf::Sprite &getSprite();

        /**
         * @brief Set the entity Sprite
         *
         * @param sprite : sprite to set
         */
        void setSprite(const sf::Sprite &sprite);

      protected:
      private:
        
        sf::Sprite _sprite;
    };
} // namespace ecs

#endif /* !DRAWABLE_HPP_ */
