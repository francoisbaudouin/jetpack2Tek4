/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include "../ecs/systems/Display.hpp"

#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/Position.hpp"

using namespace rtype;
using namespace ecs;

GameScene::GameScene(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName)
    : AScene(sceneSystem, window, sceneName)
{
}

GameScene::~GameScene() {}

void GameScene::OnCreate()
{
    _sceneSystem.getEcs()->createEntityManager(this->getName());
}

void GameScene::OnDestroy() {}

void GameScene::OnActivate()
{
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
    auto &background = _sceneSystem.getEcs()->getEntityManager(this->getName()).createEntity();
    background.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("Background"));
    background.addComponent<Position>(0, 0);
}

void GameScene::OnDeactivate() {}

void GameScene::ProcessInput() {}

void GameScene::Update() { _sceneSystem.getEcs()->getSystem<ecs::Display>().run(this->getName(), _window); }

void GameScene::Draw() {}