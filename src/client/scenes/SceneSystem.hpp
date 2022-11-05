/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#ifndef SCENESYSTEM_HPP_
#define SCENESYSTEM_HPP_

#include <memory>
#include "../TextureDatabase.hpp"
#include "../ecs/Ecs.hpp"
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
        std::string Add(std::shared_ptr<IScene> scene);
        void Remove(const std::string sceneName);
        void SwitchTo(const std::string sceneName);

        std::shared_ptr<ecs::Ecs> &getEcs();
        std::shared_ptr<rtype::TextureDatabase> &getTextureDatabase();

      private:
        std::unordered_map<std::string, std::shared_ptr<IScene>> _scenes;
        std::shared_ptr<IScene> _curScene;
        std::shared_ptr<ecs::Ecs> _manager;
        std::shared_ptr<TextureDatabase> _textureDatabase; //-> to be replaced by assetsManager
        std::string _insertedSceneName;
    };
} // namespace rtype

#endif /* !SCENESYSTEM_HPP_ */
