/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_
#include "AComponent.hpp"

namespace ecs
{
    class Drawable : public AComponent {
      public:
        /**
         * @brief Construct a new Drawable component
         *
         * @param entityId : related entity id
         */
        Drawable(const size_t entityId);
        /**
         * @brief Construct a new Drawable component
         *
         * @param entityId : related entity id
         * @param textureType : wanted type of the texture
         *
         */
        Drawable(const size_t entityId, const std::string &textureType);

        ~Drawable();

        /**
         * @brief Get the entity texture type
         *
         * @return type of the texture
         */
        std::string getTextureType() const;

        /**
         * @brief Set the entity texture type
         *
         * @param newTextureType : the new texture type to set
         */
        void setTextureType(const std::string &newTextureType);

      protected:
      private:
        std::string _textureType;
    };
} // namespace ecs

#endif /* !DRAWABLE_HPP_ */
