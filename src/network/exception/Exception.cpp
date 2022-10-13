/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Exception
*/

#include "Exception.hpp"

rtype::Exception::Exception(const std::string &str) throw() : _str(str) {}

const char *rtype::Exception::what() const throw() { return (_str.c_str()); }

rtype::Test::Test(std::string const &msg) : Exception(msg) {}

rtype::InvalideUnknownFile::InvalideUnknownFile(std::string const &msg)
    : Exception("error: " + msg + " config.ini is unreachable")
{
}
