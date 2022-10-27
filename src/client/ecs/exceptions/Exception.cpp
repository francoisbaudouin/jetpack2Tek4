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

EntityAlreadyExisting::EntityAlreadyExisting(size_t entityId)
    : Exception("error 010: Entity " + std::to_string(entityId) + " already exist")
{
}

EntityNotExisting::EntityNotExisting(size_t entityId)
    : Exception("error 011: Entity " + std::to_string(entityId) + " not existing")
{
}

SystemAlreadyExisting::SystemAlreadyExisting(std::string const &type)
    : Exception("error 030: System " + type + " already existing")
{
}

SystemNotExisting::SystemNotExisting(std::string const &type) : Exception("error 031: System " + type + " not existing")
{
}

SystemNotCompatible::SystemNotCompatible(std::string const &type)
    : Exception("error 032: System " + type + " must inherit from ISystem")
{
}

ComponentAlreadyExisting::ComponentAlreadyExisting(std::string const &type, size_t entityId)
    : Exception("error 120: Entity " + std::to_string(entityId) + " already have a " + type + " component")
{
}

ComponentNotExisting::ComponentNotExisting(std::string const &type, size_t entityId)
    : Exception("error 121: Entity " + std::to_string(entityId) + " doesn't have a " + type + " component")
{
}

ComponentNotCompatible::ComponentNotCompatible(std::string const &type)
    : Exception("error 122: Component " + type + " must inherit from IComponent")
{
}
