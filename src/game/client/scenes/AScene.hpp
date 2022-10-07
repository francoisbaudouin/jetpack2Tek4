/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <SFML/Graphics.hpp>
#include "IScene.hpp"
#include "SceneSystem.hpp"

class AScene : public IScene {
  public:
    AScene();
    ~AScene() = default;

  private:
    sf::RenderWindow &_window;
    SceneSystem &_sceneSystem;
};

#endif /* !ASCENE_HPP_ */