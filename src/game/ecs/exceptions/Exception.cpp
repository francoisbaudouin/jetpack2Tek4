/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Exception
*/

#include "Exception.hpp"

using namespace ecs;

Exception::Exception(const std::string &message) throw() : _string(message) {}

const char *Exception::what() const throw() { return (_string.c_str()); }

Test::Test(std::string const &message) : Exception(message) {}

NoComponent::NoComponent(std::string const &message, size_t entityId)
    : Exception("error: Entity " + std::to_string(entityId) + " doesn't have " + message + " component")
{
}
