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
        MainMenu(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName = "MainMenu");
        ~MainMenu();
        void OnCreate() override;
        void OnDestroy() override;
        void OnActivate() override;
        void OnDeactivate() override;
        void ProcessInput() override;
        void Update() override;
        void Draw() override;

      private:
    };
} // namespace rtype

#endif /* !MAINMENU_HPP_ */
