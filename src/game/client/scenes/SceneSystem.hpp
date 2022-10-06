/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#ifndef SCENESYSTEM_HPP_
#define SCENESYSTEM_HPP_

#include <memory>
#include <unordered_map>
#include "IScene.hpp"

class SceneSystem {
    public:
        SceneSystem();
        ~SceneSystem();

        void ProcessInput();
        void Update();
        void Draw();
        insigned int Add(std::shared_ptr<IScene> scene);
        void SwitchTo(unsigned int id);
        void Remove(unsigned int id);
    private:
        std::unordered_map<unsigned int, std::shared_ptr<IScene> scenes>;
        std::shared_ptr<IScene> curScene;
        unsigned int insertedSceneID;
};

#endif /* !SCENESYSTEM_HPP_ */
