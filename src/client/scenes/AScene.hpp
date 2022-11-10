/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <SFML/Graphics.hpp>
#include "../ecs/entity/EntityGenerator.hpp"
#include "IScene.hpp"
#include "SceneSystem.hpp"
#include <memory>

namespace rtype
{
    class AScene : public IScene {
      public:
        AScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName, const float scale,
            std::shared_ptr<Communicator> communicator);
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
        std::shared_ptr<boost::thread> getThread() override;
        /**
         * @brief get a shared ptr to the communicator 
         * 
         * @return shared_ptr to the communicator of the scene
         */
        std::shared_ptr<Communicator> getCommunicator() override;


      protected:
        rtype::SceneSystem &_sceneSystem;
        sf::RenderWindow &_window;
        std::string _sceneName;
        float _scale;
        std::shared_ptr<Communicator> _communicator;
        std::shared_ptr<boost::thread> _thread;
        ecs::EntityGenerator _entityGenerator;
      private:
    };
} // namespace rtype

#endif /* !ASCENE_HPP_ */
