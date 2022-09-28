/*
** EPITECH PROJECT, 2022
** boostrap
** File description:
** SparseArrays
*/

#include <iostream>
#include "SparseArray.hpp"
#include "components/AComponent.hpp"
#include "components/Controllable.hpp"
#include "components/Drawable.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"

// ctor ~ cpy ctor ~ dtor
template <typename Component> SparseArray<Component>::SparseArray()
{
    Component test;
    _data.push_back(test);
}

template <typename Component> SparseArray<Component>::SparseArray(SparseArray const &otherSparseArray)
{
    _data = otherSparseArray._data;
}

template <typename Component> SparseArray<Component>::SparseArray(SparseArray &&otherSparseArray) noexcept
{
    _data = otherSparseArray._data;
    otherSparseArray._data.clear();
}

template <typename Component> SparseArray<Component>::~SparseArray() {}

// operator
template <typename Component> SparseArray<Component>::reference_type SparseArray<Component>::operator[](size_t idx)
{
    return _data[idx];
}

template <typename Component>
SparseArray<Component>::const_reference_type SparseArray<Component>::operator[](size_t idx) const
{
    return _data[idx];
}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::operator=(SparseArray const &otherSparseArray)
{
    if (this != &otherSparseArray) {
        _data = otherSparseArray._data;
    }
    return *this;
}

template <typename Component>
SparseArray<Component> &SparseArray<Component>::operator=(SparseArray &&otherSparseArray) noexcept
{
    if (this != &otherSparseArray) {
        _data = otherSparseArray._data;
        otherSparseArray._data.clear();
    }
    return *this;
}
// member function

template <typename Component> SparseArray<Component>::iterator SparseArray<Component>::begin() { return _data.begin(); }

template <typename Component> SparseArray<Component>::const_iterator SparseArray<Component>::begin() const
{
    return _data.begin();
}

template <typename Component> SparseArray<Component>::const_iterator SparseArray<Component>::cbegin() const
{
    return _data.cbegin();
}

template <typename Component> SparseArray<Component>::iterator SparseArray<Component>::end() { return _data.end(); }

template <typename Component> SparseArray<Component>::const_iterator SparseArray<Component>::end() const
{
    return _data.end();
}

template <typename Component> SparseArray<Component>::const_iterator SparseArray<Component>::cend() const
{
    return _data.cend();
}

template <typename Component> SparseArray<Component>::size_type SparseArray<Component>::size() const
{
    return _data.size();
}

template <typename Component> void SparseArray<Component>::erase(size_type pos) { _data.erase(_data.begin() + pos); }

template <typename Component>
SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, Component const &component)
{
    if (pos >= _data.size()) {
        _data.push_back(component);
        return _data[_data.size()];
    }
    _data.erase(_data.begin() + pos);
    _data.insert(_data.begin() + pos, component);
    return _data[pos];
}

template <typename Component>
SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, Component &&component)
{
    if (pos >= _data.size()) {
        _data.push_back(component);
        return _data[_data.size()];
    }
    _data.erase(_data.begin() + pos);
    _data.insert(_data.begin() + pos, component);
    return _data[pos];
}

template <typename Component>
SparseArray<Component>::size_type SparseArray<Component>::get_index(
    SparseArray<Component>::value_type const &component) const
{
    size_t i = 0;
    for (; i < _data.size(); i++) {
        std::cout << std::addressof(_data[i]) << std::endl;
        if (std::addressof(component) == std::addressof(_data[i]))
            return i;
    }
    return 0;
}

template class SparseArray<AComponent>;
template class SparseArray<Position>;
template class SparseArray<Controllable>;
template class SparseArray<Velocity>;
template class SparseArray<Drawable>;
