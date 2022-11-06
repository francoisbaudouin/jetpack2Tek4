/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Hub
*/

#include "Hub.hpp"

using namespace ecs;
using namespace rtype;

Hub::Hub(SceneSystem &sceneSystem, sf::RenderWindow &window, const std::string &sceneName)
    : AScene(sceneSystem, window, sceneName)
{
}

Hub::~Hub() {}

void Hub::OnCreate()
{
    /* We are going to create system here,
    dont forget to create the corresponding entityManager */
    _sceneSystem.getEcs()->createEntityManager(this->getName());
}

void Hub::OnDestroy() {}

void Hub::OnActivate()
{
    /* wa are going to create different entity here (with they're components),
    dont forget to init the textureDatabase of the corresponding scene */
    _sceneSystem.getTextureDatabase()->onCall(this->getName());
}

void Hub::OnDeactivate() {}

void Hub::ProcessInput() {}

void Hub::Update() {}

void Hub::Draw() {}

