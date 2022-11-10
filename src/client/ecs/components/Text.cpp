/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Text
*/

#include "Text.hpp"
#include <iostream>

using namespace ecs;

Text::Text(const size_t entityId, const std::string &fontPath, const size_t fontSize, const std::string &baseString,
    const sf::Color color, const float scale)
    : AComponent(entityId), _textColor(color)
{
    if (!_font.loadFromFile(fontPath)) {
        std::cout << "error" << std::endl;
    }
    _text.setString(baseString);
    _text.setScale(sf::Vector2f(scale, scale));
    _text.setFont(_font);
    _text.setFillColor(_textColor);
    _text.setCharacterSize(fontSize);
}

Text::~Text() {}

void Text::setText(const std::string &text) { _text.setString(text); }

void Text::setText(const sf::String &text) { _text.setString(text); }

sf::Text &Text::getText() { return _text; }

void Text::setColor(const sf::Color &color)
{
    _textColor = color;
    _text.setFillColor(_textColor);
}

sf::Color Text::getColor() const { return _textColor; }

void Text::setFontSize(const size_t size) { _text.setCharacterSize(size); }

void Text::setFont(const std::string &fontPath)
{
    if (_font.loadFromFile(fontPath)) {
        // throw error
        return;
    }
    _text.setFont(_font);
}

void Text::setFont(sf::Font &font)
{
    _font = font;
    _text.setFont(_font);
}

sf::Font Text::getFont() const { return _font; }
