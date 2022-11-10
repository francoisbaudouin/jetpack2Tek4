/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Click
*/

#include "Click.hpp"
#include "../components/Selectable.hpp"

using namespace ecs;

Click::Click(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

Click::~Click() {}

bool Click::isMouseIn(sf::RenderWindow &window, HitBox &hitBox, Position &position)
{
    if (sf::Mouse::getPosition(window).x >= position.getX() && sf::Mouse::getPosition(window).x <= position.getX() + hitBox.getX()
        && sf::Mouse::getPosition(window).y >= position.getY()
        && sf::Mouse::getPosition(window).y <= position.getY() + hitBox.getY())
        return true;
    else
        return false;
}

void Click::hovered(sf::RenderWindow &window, std::shared_ptr<Entity> &entity)
{
    if (isMouseIn(window, entity->getComponent<HitBox>(), entity->getComponent<Position>()))
        entity->getComponent<Clickable>().setHovered(true);
    else
        entity->getComponent<Clickable>().setHovered(false);
}

void Click::clicked(sf::RenderWindow &window, std::shared_ptr<Entity> &entity)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (isMouseIn(window, entity->getComponent<HitBox>(), entity->getComponent<Position>())) {
            if (entity->hasComponent<Selectable>())
                entity->getComponent<Selectable>().setSelected(true);
            entity->getComponent<Clickable>().setClicked(true);
        } else {
            if (entity->hasComponent<Selectable>())
                entity->getComponent<Selectable>().setSelected(false);
            entity->getComponent<Clickable>().setClicked(false);
        }
    } else
        entity->getComponent<Clickable>().setClicked(false);
}

void Click::run(const std::string &sceneName, sf::RenderWindow &window)
{
    auto entities = _manager->getEntityManager(sceneName).getEntities();

    if (_manager->getEntityManager(sceneName).getNumberEntities() == 0)
        return;
    for (auto &entity : _manager->getEntityManager(sceneName).getEntities()) {
        if (entity.second->hasComponent<Clickable>() && entity.second->hasComponent<HitBox>()
            && entity.second->hasComponent<Position>()) {
                hovered(window, entity.second);
                clicked(window, entity.second);
            }
    }
}