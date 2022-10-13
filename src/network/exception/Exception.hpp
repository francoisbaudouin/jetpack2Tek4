/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>

namespace jetpack2tek4
{
    class Exception : public std::exception {
      public:
        Exception(std::string const &msg) throw();
        const char *what() const throw();

      protected:
      private:
        std::string _str;
    };

    class Test : public Exception {
      public:
        Test(std::string const &msg);
    };

    /*

     * LOAD CONFIG FROM FILE

    */
    class InvalideUnknownFile : public Exception {
      public:
        InvalideUnknownFile(std::string const &msg);
    };

} // namespace jetpack2tek4

#endif /* !EXCEPTION_HPP_ */
