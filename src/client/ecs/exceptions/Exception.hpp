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

    class SystemAlreadyExisting : public Exception {
      public:
        SystemAlreadyExisting(std::string const &type);
    };

    class SystemNotExisting : public Exception {
      public:
        SystemNotExisting(std::string const &type);
    };

    class EntityManagerAlreadyExisting : public Exception {
      public:
        EntityManagerAlreadyExisting(const std::string &sceneName);
    };

    class EntityManagerNotExisting : public Exception {
      public:
        EntityManagerNotExisting(const std::string &sceneName);
    };

    class SystemNotCompatible : public Exception {
      public:
        SystemNotCompatible(std::string const &type);
    };

    class ComponentAlreadyExisting : public Exception {
      public:
        ComponentAlreadyExisting(std::string const &type, const size_t entityId);
    };

    class ComponentNotExisting : public Exception {
      public:
        ComponentNotExisting(std::string const &type, const size_t entityId);
    };

    class ComponentNotCompatible : public Exception {
      public:
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
    class EntityAlreadyExisting : public Exception {
      public:
        EntityAlreadyExisting(const size_t sceneId, const size_t entityId);
    };

    class EntityNotExisting : public Exception {
      public:
        EntityNotExisting(const size_t sceneId, const size_t entityId);
    };
    class TextureNotLoadedSuccessfully : public Exception {
      public:
        TextureNotLoadedSuccessfully(std::string const &type);
    };
    class FontNotLoadedSuccessfully : public Exception {
      public:
        FontNotLoadedSuccessfully(std::string const &type);
    };
    class TypeNotInAnimationDataBase : public Exception {
      public:
        TypeNotInAnimationDataBase(std::string const &entity);
    };
    class WrongAnimationCalled : public Exception {
      public:
        WrongAnimationCalled(std::string const &entity, std::string const &animation);
    };
    class AnimationFrameOutOfRange : public Exception {
      public:
        AnimationFrameOutOfRange(std::string const &entity, std::string const &animation, const size_t maxFrame, const size_t frame);
    };
    class JsonFileOpenerFailed : public Exception {
      public:
        JsonFileOpenerFailed(std::string const &file);
    };

} // namespace ecs

#endif /* !EXCEPTION_HPP_ */
