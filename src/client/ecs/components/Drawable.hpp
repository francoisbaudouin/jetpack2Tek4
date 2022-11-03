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
        /**
         * @brief Construct a new Drawable component
         *
         * @param entityId : related entity id
         * @param texture : wanted texture for the drawable entity
         * @param scale : scale of the sprite
         */
        Drawable(const size_t entityId, const sf::Texture &texture, const float scale);
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
        /**
         * @brief Get the scale of the sprite
         * 
         * @return float scale
         */
        float getScale() const;
        /**
         * @brief Set the scale of the sprite
         * 
         * @param scale new scale of the sprite 
         */
        void setScale(const float scale);
      private:
        float _scale;
        sf::Sprite _sprite;
    };
} // namespace ecs

#endif /* !DRAWABLE_HPP_ */
