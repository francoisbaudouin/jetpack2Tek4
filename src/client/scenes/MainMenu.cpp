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
    auto &background = _sceneSystem.getEcs()->createEntity();
    background.addComponent<Drawable>(_tmpTexture);
    background.addComponent<Position>(0, 0);
    _sceneSystem.getEcs()->addSystem<Display>(_sceneSystem.getEcs());
}

void MainMenu::OnDeactivate() {}

void MainMenu::ProcessInput() {}

void MainMenu::Update()
{
    std::cout << "YES" << std::endl;
    _sceneSystem.getEcs()->getSystem<Display>();
    _sceneSystem.getEcs()->getSystem<ecs::Display>().run(_window);
}

void MainMenu::Draw() {}