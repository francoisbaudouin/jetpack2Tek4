/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** WriteInBox
*/

#include "WriteInBox.hpp"
#include "../components/HitBox.hpp"
#include "../components/Position.hpp"
#include "../components/Text.hpp"
#include "../components/TextBox.hpp"
#include "../components/Selectable.hpp"

using namespace ecs;

WriteInBox::WriteInBox(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

WriteInBox::~WriteInBox() {}

void WriteInBox::run(const std::string &sceneName, const sf::Event &event)
{
    auto entities = _manager->getEntityManager(sceneName).getEntities();

    if (_manager->getEntityManager(sceneName).getNumberEntities() == 0)
        return;
    for (auto &entity : _manager->getEntityManager(sceneName).getEntities()) {
        if (entity.second->hasComponent<TextBox>() && entity.second->hasComponent<HitBox>()
            && entity.second->hasComponent<Position>() && entity.second->hasComponent<Text>()
            && entity.second->hasComponent<Selectable>()) {
            if (entity.second->getComponent<Selectable>().isSelected()) {
                if (event.type == sf::Event::TextEntered) {
                    entity.second->getComponent<TextBox>().appendChar(event.text.unicode);
                    entity.second->getComponent<Text>().setText(entity.second->getComponent<TextBox>().getReferenceString());
                }
            }
        }
    }
}