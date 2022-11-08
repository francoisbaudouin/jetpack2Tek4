/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Exception
*/

#include "Exception.hpp"

rtype::Exception::Exception(const std::string &string) throw() : _string(string) {}

const char *rtype::Exception::what() const throw() { return (_string.c_str()); }

rtype::Test::Test(std::string const &message) : Exception(message) {}

rtype::InvalideUnknownFile::InvalideUnknownFile(std::string const &message)
    : Exception("error: " + message + " config.ini is unreachable")
{
}

rtype::InvalidConfigArgument::InvalidConfigArgument(std::string const &message)
    : Exception("error: " + message + " is not a valid argument")
{
}
