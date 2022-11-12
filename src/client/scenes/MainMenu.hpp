/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "AScene.hpp"
#include "SFML/Graphics.hpp"

namespace rtype
{
    class MainMenu : public AScene {
      public:
        /**
         * @brief Construct a new MainMenu Scene
         *
         * @param sceneSystem scene system that will manage scenes
         * @param window the window where the scene will be displayed
         * @param sceneName name of the scene
         * @param scale scale of the scene
         */
        MainMenu(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName, const float scale,
            std::shared_ptr<Communicator> communicator, boost::thread *thread);
        ~MainMenu();
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
    };
} // namespace rtype

#endif /* !MAINMENU_HPP_ */
