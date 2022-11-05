/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** DrawableClientSide
*/

#ifndef DRAWABLE_CLIENT_SIDE_HPP_
#define DRAWABLE_CLIENT_SIDE_HPP_
#include <SFML/Graphics.hpp>
#include "AComponent.hpp"

namespace ecs
{
    class DrawableClientSide : public AComponent {
      public:
        /**
         * @brief Construct a new DrawableClientSide component
         *
         * @param entityId : related entity id
         * @param texture : wanted texture for the DrawableClientSide entity
         */
        DrawableClientSide(const size_t entityId, const sf::Texture &texture);

        ~DrawableClientSide();

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

#endif /* !DRAWABLE_CLIENT_SIDE_HPP_ */
