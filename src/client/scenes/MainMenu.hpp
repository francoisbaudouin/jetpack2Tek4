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

namespace rtype {
    class MainMenu : public AScene {
      public:
        MainMenu(SceneSystem &sceneSystem, sf::RenderWindow &window);
        ~MainMenu();
        void OnCreate();
        void OnDestroy();
        void OnActivate();
        void OnDeactivate();
        void ProcessInput();
        void Update();
        void Draw();

      private:
        sf::Texture _tmpTexture;
    };
} // namespace ecs

#endif /* !MAINMENU_HPP_ */
