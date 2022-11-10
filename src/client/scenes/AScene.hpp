/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <SFML/Graphics.hpp>
#include "../ecs/entity/EntityGenerator.hpp"
#include "IScene.hpp"
#include "SceneSystem.hpp"

namespace rtype
{
    class AScene : public IScene {
      public:
        AScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName, const float scale);
        ~AScene() = default;
        /**
         * @brief Get the Name of the scene
         *
         * @return std::string name of the scene
         */
        std::string getName() const override;

      protected:
        rtype::SceneSystem &_sceneSystem;
        sf::RenderWindow &_window;
        std::string _sceneName;
        float _scale;
        ecs::EntityGenerator _entityGenerator;

      private:
    };
} // namespace rtype

#endif /* !ASCENE_HPP_ */
