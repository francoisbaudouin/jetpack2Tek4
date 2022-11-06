/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

using namespace ecs;
using namespace rtype;

MainMenu::MainMenu(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName)
    : AScene(sceneSystem, window, sceneName)
{
}

MainMenu::~MainMenu() {}

void MainMenu::OnCreate()
{
    /* We are going to create system here,
    dont forget to create the corresponding entityManager */
    _sceneSystem.getEcs()->createEntityManager(this->getName());
}

void MainMenu::OnDestroy() {}

void MainMenu::OnActivate()
{
    /* wa are going to create different entity here (with they're components),
    dont forget to init the textureDatabase of the corresponding scene */
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
}

void MainMenu::OnDeactivate() {}

void MainMenu::ProcessInput() {}

void MainMenu::Update() {}

void MainMenu::Draw() {}
