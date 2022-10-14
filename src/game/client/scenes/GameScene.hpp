/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "AScene.hpp"

class GameScene : public AScene {
    public:
        GameScene();
        ~GameScene();
        void OnCreate();
        void OnDestroy();
        void OnActivate();
        void OnDeactivate();
        void ProcessInput();
        void Update();
        void Draw();
    private:
};

#endif /* !GAMESCENE_HPP_ */
