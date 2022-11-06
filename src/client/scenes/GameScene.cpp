/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#include "GameScene.hpp"

using namespace rtype;
using namespace ecs;

GameScene::GameScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName)
    : AScene(sceneSystem, window, sceneName)
{
}

GameScene::~GameScene() {}

void GameScene::OnCreate() { _sceneSystem.getEcs()->createEntityManager(this->getName()); }

void GameScene::OnDestroy() {}

void GameScene::OnActivate() { _sceneSystem.getTextureDatabase()->onCall(this->getName()); }

void GameScene::OnDeactivate() {}

void GameScene::ProcessInput() {}

void GameScene::Update() {}

void GameScene::Draw() {}
