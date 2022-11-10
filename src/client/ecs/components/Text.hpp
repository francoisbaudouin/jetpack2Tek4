/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "AComponent.hpp"
#include "SFML/Graphics.hpp"

namespace ecs
{
    class Text : public AComponent {
      public:
        /**
         * @brief Construct a new Text component, you can click and edit it using the WriteInBox system
         *
         * @param entityId Id of the entity
         * @param fontPath path to the font
         * @param fontSize size of the font
         * @param baseString default string
         * @param color color of the font
         * @param scale scale of the font
         */
        Text(const size_t entityId, const std::string &fontPath = "assets/Boxy-Bold.ttf", const size_t fontSize = 20,
            const std::string &baseString = "Default", const sf::Color color = sf::Color::Black, const float scale = 1);
        ~Text();
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

      protected:
      private:
        sf::Font _font;
        sf::Text _text;
        sf::Color _textColor;
    };
} // namespace ecs

#endif /* !TEXT_HPP_ */
