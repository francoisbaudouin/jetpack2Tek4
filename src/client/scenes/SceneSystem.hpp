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
        /**
         * @brief Construct a new Scene System object that will manage scene (add, remove, switch)
         *
         */
        SceneSystem();
        ~SceneSystem();

        void ProcessInput();
        /**
         * @brief update will call the update of the current scene
         *
         */
        void Update();
        void Draw();
        /**
         * @brief add a scene to the _scenes property
         *
         * @param scene shared pointer to the wanted scene
         * @return std::string name of the inserted scene
         */
        std::string Add(std::shared_ptr<IScene> scene);
        /**
         * @brief remove a scene
         *
         * @param sceneName name of the scene to be removed
         */
        void Remove(const std::string sceneName);
        /**
         * @brief switch to the corresponding sceneName given in parameters
         *
         * @param sceneName name of the scene to SwitchTo
         */
        void SwitchTo(const std::string sceneName);
        /**
         * @brief Get the Ecs object
         *
         * @return reference to a shared pointer of ecs
         */
        std::shared_ptr<ecs::Ecs> &getEcs();
        /**
         * @brief Get the TextureDatabase object
         *
         * @return reference to a shared pointer of TextureDatabase
         */
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
