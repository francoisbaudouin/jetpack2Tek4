/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#include "GameScene.hpp"

using namespace rtype;
using namespace ecs;

GameScene::GameScene(
    SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator)
    : AScene(sceneSystem, window, sceneName, scale, communicator)
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
