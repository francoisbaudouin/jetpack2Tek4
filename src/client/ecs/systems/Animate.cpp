/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Animate
*/

#include "Animate.hpp"
#include "../components/AnimationFrame.hpp"
#include "../components/Clickable.hpp"
#include "../components/DrawableClientSide.hpp"
#include "../components/Selectable.hpp"
#include "../components/Text.hpp"
#include "../components/Type.hpp"
#include "../exceptions/Exception.hpp"

using namespace ecs;

Animate::Animate(std::shared_ptr<Ecs> &manager) : ASystem(manager) {}

Animate::~Animate() {}

void Animate::animateEntity(Entity &entity, rtype::AnimationDatabase &database)
{
    AnimationFrame &animationFrame = entity.getComponent<AnimationFrame>();
    size_t frame = animationFrame.getFrame();
    size_t size = database.getAnimationSize(entity.getComponent<Type>().getEntityType(), animationFrame.getAnimation());

    frame++;
    if (frame >= size)
        frame = 0;
    animationFrame.setFrame(frame);
}

void Animate::updateSprite(Entity &entity, rtype::AnimationDatabase &database)
{
    sf::Sprite &sprite = entity.getComponent<DrawableClientSide>().getSprite();
    AnimationFrame &animationFrame = entity.getComponent<AnimationFrame>();
    rtype::Frame frame = database.getFrame(
        entity.getComponent<Type>().getEntityType(), animationFrame.getAnimation(), animationFrame.getFrame());
    sf::IntRect rectangle(frame[0], frame[1], frame[2], frame[3]);

    sprite.setTextureRect(rectangle);
}

void Animate::run(const std::string &sceneId, rtype::AnimationDatabase &database)
{
    for (auto &entity : _manager->getEntityManager(sceneId).getEntities()) {
        if (entity.second->hasComponent<AnimationFrame>() && entity.second->hasComponent<Type>()
            && entity.second->hasComponent<DrawableClientSide>()) {
            animateEntity(_manager->getEntityManager(sceneId).getEntity(entity.first), database);
            updateSprite(_manager->getEntityManager(sceneId).getEntity(entity.first), database);
        }
    }
}

void Animate::runButton(const std::string &sceneId)
{
    for (auto &entity : _manager->getEntityManager(sceneId).getEntities()) {
        if (entity.second->hasComponent<Clickable>() && entity.second->hasComponent<Type>()) {
            if (entity.second->getComponent<Clickable>().isHovered())
                entity.second->getComponent<Text>().setColor(sf::Color::Blue);
            else
                entity.second->getComponent<Text>().setColor(sf::Color::White);
        }
    }
}

void Animate::runSelectable(const std::string &sceneId)
{
    for (auto &entity : _manager->getEntityManager(sceneId).getEntities()) {
        if (entity.second->hasComponent<Selectable>() && entity.second->hasComponent<Type>()) {
            if (entity.second->getComponent<Selectable>().isSelected())
                entity.second->getComponent<Text>().setColor(sf::Color::Red);
            else if (!entity.second->getComponent<Clickable>().isHovered()
                && !entity.second->getComponent<Selectable>().isSelected())
                entity.second->getComponent<Text>().setColor(sf::Color::White);
        }
    }
}
