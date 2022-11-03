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

SystemAlreadyExisting::SystemAlreadyExisting(std::string const &type)
    : Exception("Error 030: System " + type + " already existing")
{
}

SystemNotExisting::SystemNotExisting(std::string const &type) : Exception("Error 031: System " + type + " not existing")
{
}

EntityManagerAlreadyExisting::EntityManagerAlreadyExisting(size_t const id)
    : Exception("Error 040: EntityManager " + std::to_string(id) + " already existing")
{
}

EntityManagerNotExisting::EntityManagerNotExisting(size_t const id)
    : Exception("Error 041: EntityManager " + std::to_string(id) + " not existing")
{
}

SystemNotCompatible::SystemNotCompatible(std::string const &type)
    : Exception("Error 032: System " + type + " must inherit from ISystem")
{
}

ComponentAlreadyExisting::ComponentAlreadyExisting(std::string const &type, size_t entityId)
    : Exception("Error 120: Entity " + std::to_string(entityId) + " already have a " + type + " component")
{
}

ComponentNotExisting::ComponentNotExisting(std::string const &type, size_t entityId)
    : Exception("Error 121: Entity " + std::to_string(entityId) + " doesn't have a " + type + " component")
{
}

ComponentNotCompatible::ComponentNotCompatible(std::string const &type)
    : Exception("Error 122: Component " + type + " must inherit from IComponent")
{
}

EntityAlreadyExisting::EntityAlreadyExisting(const size_t sceneId, const size_t entityId)
    : Exception(
        "Error 410: in Manager " + std::to_string(sceneId) + " Entity " + std::to_string(entityId) + " already exist")
{
}

EntityNotExisting::EntityNotExisting(const size_t sceneId, const size_t entityId)
    : Exception(
        "Error 411: in Manager " + std::to_string(sceneId) + " Entity " + std::to_string(entityId) + " not existing")
{
}
