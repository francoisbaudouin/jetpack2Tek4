/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** TextBox
*/

#include "TextBox.hpp"
#include <iostream>

using namespace ecs;

TextBox::TextBox(const size_t entityId, const size_t maxLenght) : AComponent(entityId), _maxLenght(maxLenght) {}

TextBox::~TextBox() {}

void TextBox::appendChar(const char &charToAppend)
{
    if (charToAppend == '\b') {
        this->eraseLast();
        return;
    }
    if (_referenceString.size() >= _maxLenght)
        return;
    _referenceString.push_back(charToAppend);
}

void TextBox::eraseLast()
{
    if (_referenceString.size() > 0) {
        _referenceString.pop_back();
    }
}

std::string TextBox::getReferenceString() const { return _referenceString; }

void TextBox::setMaxLenght(const size_t maxLenght) { _maxLenght = maxLenght; }

size_t TextBox::getMaxLenght() const { return _maxLenght; }
