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

namespace rtype {
  class AScene : public IScene {
    public:
      AScene(SceneSystem &sceneSystem, sf::RenderWindow &window);
      ~AScene() = default;

    protected:
      sf::RenderWindow &_window;
      rtype::SceneSystem &_sceneSystem;
    private:
  };
}

#endif /* !ASCENE_HPP_ */