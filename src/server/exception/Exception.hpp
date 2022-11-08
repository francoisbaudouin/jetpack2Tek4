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

namespace rtype
{
    class Exception : public std::exception {
      public:
        Exception(std::string const &message) throw();
        const char *what() const throw() override;

      protected:
      private:
        std::string _string;
    };

    class Test : public Exception {
      public:
        Test(std::string const &message);
    };

    /*

     * LOAD CONFIG FROM FILE

    */
    class InvalideUnknownFile : public Exception {
      public:
        InvalideUnknownFile(std::string const &message);
    };

    class InvalidConfigArgument : public Exception {
      public:
        InvalidConfigArgument(std::string const &message);
    };

} // namespace rtype

#endif /* !EXCEPTION_HPP_ */
