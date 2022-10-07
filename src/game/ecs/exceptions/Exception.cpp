/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Exception
*/

#include "Exception.hpp"

using namespace ecs;

Exception::Exception(const std::string &str) throw() : _str(str) {}

const char *Exception::what() const throw() { return (_str.c_str()); }

Test::Test(std::string const &msg) : Exception(msg) {}

NoComponent::NoComponent(std::string const &msg, size_t entityId)
: Exception("error: Entity " + std::to_string(entityId) + " doesn't have " + msg + " component") {}
