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
#include <unordered_map>

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

  private:
    std::unordered_map<unsigned int, std::shared_ptr<IScene>> _scenes;
    std::shared_ptr<IScene> _curScene;
    unsigned int _insertedSceneID;
};

#endif /* !SCENESYSTEM_HPP_ */
