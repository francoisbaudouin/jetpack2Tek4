/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** jsonFileOpener
*/

#ifndef FILEOPENER_HPP_
#define FILEOPENER_HPP_

#include <string>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

namespace rtype
{
    std::string fileTraduction(std::string &fileName);
    boost::property_tree::ptree openJsonFile(std::string &fileName);
} // namespace rtype

#endif /* !FILEOPENER_HPP_ */
