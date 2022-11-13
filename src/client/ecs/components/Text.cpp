/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Text
*/

#include "Text.hpp"
#include "../exceptions/Exception.hpp"

using namespace ecs;

Text::Text(const size_t entityId, const std::string &fontPath, const size_t fontSize, const std::string &baseString,
    const sf::Color color, const float scale)
    : AComponent(entityId), _textColor(color)
{
    if (!_font.loadFromFile(fontPath))
        throw FontNotLoadedSuccessfully(fontPath);
    _text.setString(baseString);
    _text.setScale(sf::Vector2f(scale, scale));
    _text.setFont(_font);
    _text.setFillColor(_textColor);
    _text.setCharacterSize(fontSize);
}

Text::~Text() {}

void Text::setText(const std::string &text) { _text.setString(text); }

void Text::setText(const sf::String &text) { _text.setString(text); }

void Text::setScale(const size_t scale) { _text.setScale(sf::Vector2f(scale, scale)); }

size_t Text::getTextSize() const { return _text.getString().getSize(); }

float Text::getTextWidth() const { return _text.getGlobalBounds().width; }

float Text::getTextHeight() const { return _text.getGlobalBounds().height; }

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
    if (!_font.loadFromFile(fontPath)) {
        throw FontNotLoadedSuccessfully(fontPath);
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

size_t Text::getFontSize() const { return _text.getCharacterSize(); }
