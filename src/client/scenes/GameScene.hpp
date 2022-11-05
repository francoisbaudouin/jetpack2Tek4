/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "AScene.hpp"

namespace rtype
{
    class GameScene : public AScene {
      public:
        GameScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName = "Game");
        ~GameScene();
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

#endif /* !GAMESCENE_HPP_ */
