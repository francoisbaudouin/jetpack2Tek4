/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Lobby
*/

#ifndef LOBBY_HPP_
#define LOBBY_HPP_

#include "AScene.hpp"

namespace rtype
{
    class Lobby : public AScene {
      public:
        /**
         * @brief Construct a new Lobby Scene
         *
         * @param sceneSystem scene system that will manage scenes
         * @param window the window where the scene will be displayed
         * @param sceneName name of the scene
         * @param scale scale of the scene
         *
         */
        Lobby(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, sf::Event &event,
            const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator,
            boost::thread *thread);
        ~Lobby();
        /**
         * @brief function called at creation of the scene (Add of sceneSystem)
         *
         */
        void OnCreate() override;
        /**
         * @brief function called at destruction of the scene (Remove of scene system)
         *
         */
        void OnDestroy() override;
        /**
         * @brief function called at activation of the scene (SwitchTo of scene system)
         *
         */
        void OnActivate() override;
        /**
         * @brief function called at desactivation of the scene (SwitchTo will desactivate the old scene)
         *
         */
        void OnDeactivate() override;
        void ProcessInput() override;
        /**
         * @brief function that will be called each loop. This is the update of the loop
         *
         */
        void Update() override;
        void Draw() override;

      private:
        void updateEntity(ecs::Entity &entity, std::string data);
        void createEntity(std::string data, const size_t entityId);
        sf::Event &_event;
    };
} // namespace rtype

#endif /* !LOBBY_HPP_ */
