/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <boost/thread/thread.hpp>
#include <memory>
#include "../Communicator.hpp"

namespace rtype
{
    class IScene {
      public:
        virtual ~IScene() = default;
        virtual void OnCreate() = 0;
        virtual void OnDestroy() = 0;
        virtual void OnActivate() = 0;
        virtual void OnDeactivate() = 0;
        virtual void ProcessInput() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual std::string getName() const = 0;
        virtual boost::thread *getThread() = 0;
        virtual std::shared_ptr<Communicator> getCommunicator() = 0;
        virtual size_t getId() const = 0;
        virtual void setId(const size_t &id) = 0;
    };
} // namespace rtype

#endif /* !ISCENE_HPP_ */
