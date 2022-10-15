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
        /**
         * @brief Construct a new Exception object
         *
         * @param message : message to throw
         */
        Exception(std::string const &message) throw();
        /**
         * @brief return the message
         *
         * @return const char* : message
         */
        const char *what() const throw() override;

      protected:
      private:
        std::string _string;
    };

    class Test : public Exception {
      public:
        /**
         * @brief exception threw during test
         *
         * @param message : message to throw
         */
        Test(std::string const &message);
    };

    class NoComponent : public Exception {
      public:
        /**
         * @brief exception threw if an entity doesn't have the component needed
         *
         * @param message : message to throw
         * @param entityId : id of the entity
         */
        NoComponent(std::string const &message, const size_t entityId);
    };
} // namespace ecs

#endif /* !EXCEPTION_HPP_ */
