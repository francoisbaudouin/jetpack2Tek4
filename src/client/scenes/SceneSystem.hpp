/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#ifndef SCENESYSTEM_HPP_
#define SCENESYSTEM_HPP_

#include <memory>
#include "../ecs/Ecs.hpp"
#include "../ecs/components/Drawable.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/systems/Display.hpp"
#include "IScene.hpp"
#include <unordered_map>

namespace rtype
{
    class SceneSystem {
      public:
        SceneSystem();
        ~SceneSystem();

        void ProcessInput();
        void Update();
        void Draw();
        std::string Add(std::shared_ptr<IScene> scene, const std::string sceneName);
        void Remove(const std::string id);
        void SwitchTo(const std::string id);

        std::shared_ptr<ecs::Ecs> &getEcs();

      private:
        std::unordered_map<std::string, std::shared_ptr<IScene>> _scenes;
        std::shared_ptr<IScene> _curScene;
        std::shared_ptr<ecs::Ecs> _manager;
        std::string _insertedSceneName;
    };
} // namespace rtype

#endif /* !SCENESYSTEM_HPP_ */
