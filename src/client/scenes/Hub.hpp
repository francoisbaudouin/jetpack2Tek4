/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Hub
*/

#ifndef HUB_HPP_
#define HUB_HPP_

#include "../Communicator.hpp"
#include "AScene.hpp"

namespace rtype
{
    class Hub : public AScene {
      public:
        /**
         * @brief Construct a new Hub Scene
         *
         * @param sceneSystem scene system that will manage scenes
         * @param window the window where the scene will be displayed
         * @param sceneName name of the scene
         * @param scale scale of the scene
         *
         */
        Hub(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, sf::Event &event,
            const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator,
            boost::thread *thread);
        ~Hub();
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
        sf::Event &_event;
        std::string _ipServer;
        std::string _portServer;
    };
} // namespace rtype

#endif /* !HUB_HPP_ */
