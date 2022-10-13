/*
** EPITECH PROJECT, 2022
** jetpack2tek4
** File description:
** Exception
*/

#include "Exception.hpp"

jetpack2tek4::Exception::Exception(const std::string &str) throw() : _str(str) {}

const char *jetpack2tek4::Exception::what() const throw() { return (_str.c_str()); }

jetpack2tek4::Test::Test(std::string const &msg) : Exception(msg) {}

jetpack2tek4::InvalideUnknownFile::InvalideUnknownFile(std::string const &msg)
    : Exception("error: " + msg + " config.ini is unreachable")
{
}
