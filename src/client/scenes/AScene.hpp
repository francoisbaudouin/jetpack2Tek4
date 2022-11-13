/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include "../ecs/entity/EntityGenerator.hpp"
#include "IScene.hpp"
#include "SceneSystem.hpp"
namespace rtype
{
    class AScene : public IScene {
      public:
        AScene(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, const std::string &sceneName,
            const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread);
        ~AScene() = default;
        /**
         * @brief Get the Name of the scene
         *
         * @return std::string name of the scene
         */
        std::string getName() const override;
        /**
         * @brief Get the Thread of the scene
         *
         * @return ptr to the thread of the scene
         */
        boost::thread *getThread() override;
        /**
         * @brief get a shared ptr to the communicator
         *
         * @return shared_ptr to the communicator of the scene
         */
        std::shared_ptr<Communicator> getCommunicator() override;
        size_t getId() const override;
        void setId(const size_t &id) override;

      protected:
        std::shared_ptr<rtype::SceneSystem> _sceneSystem;
        sf::RenderWindow &_window;
        std::string _sceneName;
        float _scale;
        std::shared_ptr<Communicator> _communicator;
        boost::thread *_thread;
        size_t _id;

      private:
    };
} // namespace rtype

#endif /* !ASCENE_HPP_ */
