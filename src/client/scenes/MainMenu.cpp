/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

#include "../ecs/systems/Display.hpp"

#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/Position.hpp"

#include <ostream>

using namespace ecs;
using namespace rtype;

MainMenu::MainMenu(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName) : AScene(sceneSystem, window, sceneName) {}

MainMenu::~MainMenu() {}

void MainMenu::OnCreate()
{
    _sceneSystem.getEcs()->createEntityManager(this->getName());
    _sceneSystem.getEcs()->createSystem<Display>(_sceneSystem.getEcs());
}

void MainMenu::OnDestroy() {}

void MainMenu::OnActivate()
{
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
    auto &background = _sceneSystem.getEcs()->getEntityManager(this->getName()).createEntity();
    background.addComponent<DrawableClientSide>(_sceneSystem.getTextureDatabase()->getTexture("Background"));
    background.addComponent<Position>(0, 0);
}

void MainMenu::OnDeactivate() {}

void MainMenu::ProcessInput() {}

void MainMenu::Update()
{
    _sceneSystem.getEcs()->getSystem<ecs::Display>().run(this->getName(), _window);
}

void MainMenu::Draw() {}