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

    class EntityAlreadyExisting : public Exception {
      public:
        /**
         * @brief exception threw if an entity doesn't have the component needed
         *
         * @param entityId : id of the entity
         */
        EntityAlreadyExisting(const size_t entityId);
    };

    class EntityNotExisting : public Exception {
      public:
        /**
         * @brief exception threw if an entity doesn't have the component needed
         *
         * @param entityId : id of the entity
         */
        EntityNotExisting(const size_t entityId);
    };

    class SystemAlreadyExisting : public Exception {
      public:
        /**
         * @brief exception threw if a system already exist in the Ecs
         *
         * @param type : type of the system that causes the error
         */
        SystemAlreadyExisting(std::string const &type);
    };

    class SystemNotExisting : public Exception {
      public:
        /**
         * @brief exception threw if a system already exist in the Ecs
         *
         * @param type : type of the system that causes the error
         */
        SystemNotExisting(std::string const &type);
    };

    class SystemNotCompatible : public Exception {
      public:
        /**
         * @brief exception threw if a system already exist in the Ecs
         *
         * @param type : type of the system that causes the error
         */
        SystemNotCompatible(std::string const &type);
    };

    class ComponentAlreadyExisting : public Exception {
      public:
        /**
         * @brief exception threw if an entity doesn't have the component needed
         *
         * @param type : type of the component that causes the error
         * @param entityId : id of the entity
         */
        ComponentAlreadyExisting(std::string const &type, const size_t entityId);
    };

    class ComponentNotExisting : public Exception {
      public:
        /**
         * @brief exception threw if an entity doesn't have the component needed
         *
         * @param type : type of the component that causes the error
         * @param entityId : id of the entity
         */
        ComponentNotExisting(std::string const &type, const size_t entityId);
    };

    class ComponentNotCompatible : public Exception {
      public:
        /**
         * @brief exception threw if an entity doesn't have the component needed
         *
         * @param type : type of the component that causes the error
         */
        ComponentNotCompatible(std::string const &type);
    };
    class TextureNotInDatabase : public Exception {
      public:
        /**
         * @brief exception threw if drawable component does't find a texture at specified type
         *
         * @param type : type of the entity
         */
        TextureNotInDatabase(std::string const &type);
    };
} // namespace ecs

#endif /* !EXCEPTION_HPP_ */
