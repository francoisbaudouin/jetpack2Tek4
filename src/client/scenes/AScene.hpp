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
      rtype::SceneSystem &_sceneSystem;
      sf::RenderWindow &_window;
    private:
  };
}

#endif /* !ASCENE_HPP_ */