/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** WriteInBox
*/

#include "WriteInBox.hpp"
#include "../components/HitBox.hpp"
#include "../components/Position.hpp"
#include "../components/TextBox.hpp"

using namespace ecs;

WriteInBox::WriteInBox(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

WriteInBox::~WriteInBox() {}

bool isInBox(int x, int y, std::shared_ptr<Entity> &box)
{
    auto &boxBounds = box->getComponent<HitBox>();
    auto &boxPosition = box->getComponent<Position>();
    if ((x <= boxPosition.getX() + boxBounds.getX() && x >= boxPosition.getX())
        && (y <= boxPosition.getY() + boxBounds.getY() && y >= boxPosition.getY())) {
        return true;
    } else
        return false;
}

void selection(std::shared_ptr<Entity> &box, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        auto &entityTextBox = box->getComponent<TextBox>();
        if (isInBox(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, box)) {
            entityTextBox.isSelected(true);
        } else {
            entityTextBox.isSelected(false);
        }
    }
}

void WriteInBox::run(const std::string &sceneName, const sf::Event &event, sf::RenderWindow &window)
{
    auto entities = _manager->getEntityManager(sceneName).getEntities();

    if (_manager->getEntityManager(sceneName).getNumberEntities() == 0)
        return;
    for (auto &entity : _manager->getEntityManager(sceneName).getEntities()) {
        if (entity.second->hasComponent<TextBox>() && entity.second->hasComponent<HitBox>()
            && entity.second->hasComponent<Position>()) {
            selection(entity.second, window);
            if (entity.second->getComponent<TextBox>().getSelected()) {
                if (event.type == sf::Event::TextEntered)
                    entity.second->getComponent<TextBox>().appendChar(event.text.unicode);
            }
        }
    }
}