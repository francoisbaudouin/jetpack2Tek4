/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include "AComponent.hpp"
#include "SFML/Graphics/Text.hpp"

namespace ecs
{
    class TextBox : public AComponent {
      public:
        /**
         * @brief Construct a new TextBox component, you can click and edit it using the WriteInBox system
         *
         * @param entityId Id of the entity
         * @param maxLenght max lenght of the string that you can type
         */
        TextBox(const size_t entityId, const size_t maxLenght = 20);
        ~TextBox();
        /**
         * @brief append a char to the text
         *
         * @param charToAppend char that will be added at the end
         */
        void appendChar(const char &charToAppend);
        /**
         * @brief erease the last char
         */
        void eraseLast();
        /**
         * @brief Get the Reference String of the text
         *
         * @return std::string of the text
         */
        std::string getReferenceString() const;
        /**
         * @brief Set the Max Lenght of the text
         *
         * @param maxLenght max lenght of the text
         */
        void setMaxLenght(const size_t maxLenght);
        /**
         * @brief Get the Max Lenght of the text
         *
         * @return size_t max lenght of the text
         */
        size_t getMaxLenght() const;

      private:
        size_t _maxLenght;
        std::string _referenceString;
    };
} // namespace ecs

#endif /* !TEXTBOX_HPP_ */
