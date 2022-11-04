/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#include "SceneSystem.hpp"

using namespace rtype;
using namespace ecs;

SceneSystem::SceneSystem() : _scenes(0), _curScene(0), _insertedSceneID(0)
{
    ecs::Ecs ecs;
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

unsigned int SceneSystem::Add(std::shared_ptr<IScene> scene)
{
    auto inserted = _scenes.insert(std::make_pair(_insertedSceneID, scene));
    _insertedSceneID++;
    inserted.first->second->OnCreate();
    return _insertedSceneID - 1;
}

void SceneSystem::Remove(unsigned int id)
{
    auto it = _scenes.find(id);
    if (it != _scenes.end()) {
        if (_curScene == it->second)
            _curScene = nullptr;
        it->second->OnDestroy();
        _scenes.erase(it);
    }
}

void SceneSystem::SwitchTo(unsigned int id)
{
    auto it = _scenes.find(id);
    std::cout << id << std::endl;
    if (it != _scenes.end()) {
        if (_curScene)
            _curScene->OnDeactivate();
        _curScene = it->second;
        _curScene->OnActivate();
    }
}

std::shared_ptr<Ecs> &SceneSystem::getEcs()
{
    return (_manager);
}