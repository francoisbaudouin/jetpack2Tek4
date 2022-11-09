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
         * @param fontPath path to the font
         * @param fontSize size of the font
         * @param baseString default string
         * @param color color of the font
         * @param scale scale of the font
         * @param maxLenght max lenght of the string that you can type
         */
        TextBox(const size_t entityId, const std::string &fontPath = "assets/arial.ttf", const size_t fontSize = 20,
            const std::string &baseString = "Default", const sf::Color color = sf::Color::Black, const float scale = 1,
            const size_t maxLenght = 20);
        ~TextBox();
        /**
         * @brief Set the text Property
         *
         * @param text std::string of the text to set
         */
        void setText(const std::string &text);
        /**
         * @brief Set the text Property
         *
         * @param text sf::String of the text to set
         */
        void setText(const sf::String &text);
        /**
         * @brief Get the Text property
         *
         * @return text of the component
         */
        sf::Text &getText();
        /**
         * @brief set the selected property to the bool given in parameter
         *
         * @param isSelected selected will take this value
         */
        void isSelected(bool isSelected);
        /**
         * @brief Get the Selected property
         *
         * @return true if selected
         * @return false if not selecred
         */
        bool getSelected() const;
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
         * @brief Set the color of the text
         *
         * @param color color of the text
         */
        void setColor(const sf::Color &color);
        /**
         * @brief Get the Color of the text (default to black)
         *
         */
        sf::Color getColor() const;
        /**
         * @brief Set the Font of the text
         * 
         * @param fontPath path to the font
         */
        void setFont(const std::string &fontPath);
        /**
         * @brief Set the Font of the text
         * 
         * @param font  object font already loaded
         */
        void setFont(sf::Font &font);
        /**
         * @brief Get the Font of the text
         * 
         * @return sf::Font font of the text
         */
        sf::Font getFont() const;
        /**
         * @brief Set the Font Size of the text
         * 
         * @param size font size of the text
         */
        void setFontSize(const size_t size);
        /**
         * @brief Get the Font size of the text
         * 
         * @return size_t size of the text
         */
        size_t getFontSize() const;
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
        bool _selected;
        size_t _maxLenght;
        sf::Font _font;
        std::string _referenceString;
        sf::Text _text;
        sf::Color _textColor;
    };
} // namespace ecs

#endif /* !TEXTBOX_HPP_ */
