/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#include "SceneSystem.hpp"

SceneSystem::SceneSystem() {}

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

unsigned int SceneSystem::Add(std::shared_ptr<Scene> scene)
{
    auto inserted = scenes.insert(std::make_pair(_insertedSceneID, scene));
    _insertedSceneID++;
    inserted.first->second->OnCreate();
    return _insertedSceneID - 1;
}

void SceneSystem::Remove(unsigned int id)
{
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (_curScene == it->second)
            _curScene = nullptr;
        it->second->OnDestroy();
        scenes.erase(it);
    }
}

void SceneSystem::SwitchTo(unsigned int id)
{
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (_curScene)
            _curScene->OnDeactivate();
        _curScene = it->second;
        _curScene->OnActivate();
    }
}