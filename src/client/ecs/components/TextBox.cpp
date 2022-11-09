/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextBox
*/

#include "TextBox.hpp"
#include <iostream>

using namespace ecs;

TextBox::TextBox(const size_t entityId, const std::string &fontPath, const size_t fontSize,
    const std::string &baseString, const sf::Color color, const float scale, const size_t maxLenght)
    : AComponent(entityId), _selected(false), _maxLenght(maxLenght), _textColor(color)
{
    if (!_font.loadFromFile(fontPath)) {
        std::cout << "error" << std::endl;
    }
    _text.setString(baseString);
    _text.setScale(sf::Vector2f(scale, scale));
    _text.setFont(_font);
    _text.setColor(_textColor);
    _text.setCharacterSize(fontSize);
}

TextBox::~TextBox() {}

void TextBox::setText(const sf::String &text) { _text.setString(text); }

sf::Text &TextBox::getText() { return _text; }

void TextBox::isSelected(const bool isSelected) { _selected = isSelected; }

void TextBox::appendChar(const char &charToAppend)
{
    if (charToAppend == '\b') {
        this->eraseLast();
        return;
    }
    if (_referenceString.size() >= _maxLenght)
        return;
    _referenceString.push_back(charToAppend);
    _text.setString(_referenceString);
}

void TextBox::eraseLast()
{
    if (_referenceString.size() > 0) {
        _referenceString.pop_back();
        _text.setString(_referenceString);
    }
}

bool TextBox::getSelected() const { return _selected; }

void TextBox::setColor(const sf::Color &color)
{
    _textColor = color;
    _text.setColor(_textColor);
}

sf::Color TextBox::getColor() const { return _textColor; }

void TextBox::setFontSize(const size_t size) { _text.setCharacterSize(size); }

void TextBox::setFont(const std::string &fontPath)
{
    if (_font.loadFromFile(fontPath)) {
        // throw error
        return;
    }
    _text.setFont(_font);
}

void TextBox::setFont(sf::Font &font)
{
    _font = font;
    _text.setFont(_font);
}

sf::Font TextBox::getFont() const { return _font; }

std::string TextBox::getReferenceString() const { return _referenceString; }

void TextBox::setMaxLenght(const size_t maxLenght) { _maxLenght = maxLenght; }

size_t TextBox::getMaxLenght() const { return _maxLenght; }
