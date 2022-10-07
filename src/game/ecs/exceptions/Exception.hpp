/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>

namespace ecs
{
    class Exception : public std::exception {
      public:
        Exception(std::string const &msg) throw();
        const char *what() const throw() override;

      protected:
      private:
        std::string _str;
    };

    class Test : public Exception {
      public:
        Test(std::string const &msg);
    };

    class NoComponent : public Exception {
      public:
        NoComponent(std::string const &msg, const size_t entityId);
    };
} // namespace ecs

#endif /* !EXCEPTION_HPP_ */
