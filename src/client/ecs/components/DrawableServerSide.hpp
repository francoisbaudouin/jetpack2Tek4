/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** DrawableServerSide
*/

#ifndef DRAWABLE_SERVER_SIDE_HPP_
#define DRAWABLE_SERVER_SIDE_HPP_
#include "AComponent.hpp"

namespace ecs
{
    class DrawableServerSide : public AComponent {
      public:
        /**
         * @brief Construct a new DrawableServerSide component
         *
         * @param entityId : related entity id
         */
        DrawableServerSide(const size_t entityId);
        /**
         * @brief Construct a new DrawableServerSide component
         *
         * @param entityId : related entity id
         * @param textureType : wanted type of the texture
         *
         */
        DrawableServerSide(const size_t entityId, const std::string &textureType);

        ~DrawableServerSide();

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

#endif /* !DRAWABLE_SERVER_SIDE_HPP_ */
