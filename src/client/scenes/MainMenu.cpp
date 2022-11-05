/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** MainMenu
*/

#include "MainMenu.hpp"
#include <ostream>

using namespace ecs;
using namespace rtype;

MainMenu::MainMenu(SceneSystem &sceneSystem, sf::RenderWindow &window) : AScene(sceneSystem, window) {}

MainMenu::~MainMenu() {}

void MainMenu::OnCreate() {}

void MainMenu::OnDestroy() {}

void MainMenu::OnActivate()
{
    _tmpTexture.loadFromFile("assets/Parallax.png");
    auto &background = _sceneSystem.getEcs()->getEntityManager("MainMenu").createEntity();
    background.addComponent<Drawable>(_tmpTexture);
    background.addComponent<Position>(0, 0);
    _sceneSystem.getEcs()->createSystem<Display>(_sceneSystem.getEcs());
}

void MainMenu::OnDeactivate() {}

void MainMenu::ProcessInput() {}

void MainMenu::Update()
{
    _sceneSystem.getEcs()->getSystem<ecs::Display>().run("MainMenu", _window);
}

void MainMenu::Draw() {}