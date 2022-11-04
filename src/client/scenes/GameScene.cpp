/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** GameScene
*/

#include "GameScene.hpp"

using namespace rtype;

GameScene::GameScene(SceneSystem &sceneSystem, sf::RenderWindow &window) : AScene(sceneSystem, window) {}

GameScene::~GameScene() {}

void GameScene::OnCreate() {}

void GameScene::OnDestroy() {}

void GameScene::OnActivate() { Update(); }

void GameScene::OnDeactivate() {}

void GameScene::ProcessInput() {}

void GameScene::Update() {}

void GameScene::Draw() {}