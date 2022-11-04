/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#ifndef SCENESYSTEM_HPP_
#define SCENESYSTEM_HPP_

#include <memory>
#include "IScene.hpp"
#include "../ecs/Ecs.hpp"
#include "../ecs/components/Drawable.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/systems/Display.hpp"
#include <unordered_map>

namespace rtype {
  class SceneSystem {
    public:
      SceneSystem();
      ~SceneSystem();

      void ProcessInput();
      void Update();
      void Draw();
      unsigned int Add(std::shared_ptr<IScene> scene);
      void Remove(unsigned int id);
      void SwitchTo(unsigned int id);

      std::shared_ptr<ecs::Ecs> &getEcs();

    private:
      std::unordered_map<unsigned int, std::shared_ptr<IScene>> _scenes;
      std::shared_ptr<IScene> _curScene;
      std::shared_ptr<ecs::Ecs> _manager;
      unsigned int _insertedSceneID;
  };
} //namespace ecs

#endif /* !SCENESYSTEM_HPP_ */
