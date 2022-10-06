/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** SceneSystem
*/

#include "SceneSystem.hpp"

SceneSystem::SceneSystem()
{
}

SceneSystem::~SceneSystem()
{
}

void SceneSystem::ProcessInput()
{
    if (curScene) {
        curScene->ProcessInput();
    }
}

void SceneSystem::Update()
{
    if (curScene) {
        curScene->Update();
    }
}

void SceneSystem::Draw()
{
    if (curScene) {
        curScene->Draw();
    }
}