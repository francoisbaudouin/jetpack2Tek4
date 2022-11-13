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

EntityManagerAlreadyExisting::EntityManagerAlreadyExisting(const std::string &sceneName)
    : Exception("Error 040: EntityManager " + sceneName + " already existing")
{
}

EntityManagerNotExisting::EntityManagerNotExisting(const std::string &sceneName)
    : Exception("Error 041: EntityManager " + sceneName + " not existing")
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

TextureNotInDatabase::TextureNotInDatabase(std::string const &type)
    : Exception("error 550: Texture " + type + " not exist in database, please check the configuration file")
{
}

TextureNotLoadedSuccessfully::TextureNotLoadedSuccessfully(std::string const &type)
    : Exception("error 551: Texture " + type + " not successefully loaded")
{
}

FontNotLoadedSuccessfully::FontNotLoadedSuccessfully(std::string const &type)
    : Exception("error 260: Font " + type + " not successefully loaded")
{
}

TypeNotInAnimationDataBase::TypeNotInAnimationDataBase(std::string const &entity)
    : Exception("error 920: Type '" + entity + "' not in animation database")
{
}

WrongAnimationCalled::WrongAnimationCalled(std::string const &entity, std::string const &animation)
    : Exception("Error 770: Type " + entity + ": " + animation + " does not exist")
{
}

AnimationFrameOutOfRange::AnimationFrameOutOfRange(
    std::string const &entity, std::string const &animation, const size_t maxFrame, const size_t frame)
    : Exception("Error 771: Type " + entity + ": frame in " + animation + " out of range " + std::to_string(frame) + "/"
        + std::to_string(maxFrame))
{
}

JsonFileOpenerFailed::JsonFileOpenerFailed(std::string const &file)
    : Exception("error 880: Json file does not exist: '" + file + "'")
{
}

CannotOpenMusic::CannotOpenMusic(std::string const &file)
    : Exception("error 881: cannot open '" + file + "'")
{
}
