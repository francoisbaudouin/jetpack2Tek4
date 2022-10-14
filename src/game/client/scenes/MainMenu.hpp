/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "AScene.hpp"

class MainMenu : public AScene {
    public:
        MainMenu();
        ~MainMenu();
        void OnCreate();
        void OnDestroy();
        void OnActivate();
        void OnDeactivate();
        void ProcessInput();
        void Update();
        void Draw();
    private:
};

#endif /* !MAINMENU_HPP_ */
