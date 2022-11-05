/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#include "SceneSystem.hpp"

using namespace rtype;
using namespace ecs;

SceneSystem::SceneSystem() : _scenes(0), _curScene(0), _insertedSceneName("Not Defined")
{
    ecs::Ecs ecs;
    TextureDatabase textureDatabase;

    this->_textureDatabase = std::make_shared<TextureDatabase>(textureDatabase);
    this->_manager = std::make_shared<ecs::Ecs>(ecs);
}

SceneSystem::~SceneSystem() {}

void SceneSystem::ProcessInput()
{
    if (_curScene)
        _curScene->ProcessInput();
}

void SceneSystem::Update()
{
    if (_curScene)
        _curScene->Update();
}

void SceneSystem::Draw()
{
    if (_curScene)
        _curScene->Draw();
}

std::string SceneSystem::Add(std::shared_ptr<IScene> scene, const std::string sceneName)
{
    _insertedSceneName = sceneName;
    auto inserted = _scenes.insert(std::make_pair(_insertedSceneName, scene));
    inserted.first->second->OnCreate();
    return _insertedSceneName;
}

void SceneSystem::Remove(const std::string sceneName)
{
    auto it = _scenes.find(sceneName);
    if (it != _scenes.end()) {
        if (_curScene == it->second)
            _curScene = nullptr;
        it->second->OnDestroy();
        _scenes.erase(it);
    }
}

void SceneSystem::SwitchTo(const std::string sceneName)
{
    auto it = _scenes.find(sceneName);
    if (it != _scenes.end()) {
        if (_curScene)
            _curScene->OnDeactivate();
        _curScene = it->second;
        _curScene->OnActivate();
    }
}

std::shared_ptr<Ecs> &SceneSystem::getEcs() { return (_manager); }