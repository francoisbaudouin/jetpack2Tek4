/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** TestGame
*/

#include "TestGame.hpp"

#include "ecs/components/AnimationFrame.hpp"
#include "ecs/components/DrawableClientSide.hpp"
#include "ecs/components/DrawableServerSide.hpp"
#include "ecs/components/HitBox.hpp"
#include "ecs/components/Weapon.hpp"
#include "ecs/entity/EntityGenerator.hpp"
#include "ecs/systems/Animate.hpp"
#include "ecs/systems/Collider.hpp"
#include "ecs/systems/ColliderReaction.hpp"
#include "ecs/systems/Controll.hpp"
#include "ecs/systems/Display.hpp"
#include "ecs/systems/Fire.hpp"
#include "ecs/systems/Input.hpp"
#include "ecs/systems/Move.hpp"

#include "game/EnemyWave.hpp"

using namespace rtype;

TestGame::TestGame() : _playerId(0), _window(sf::VideoMode(640, 360), "Subaquatica"), _animations(), _timers()
{
    _manager = std::make_shared<ecs::Ecs>(ecs::Ecs());
    _textures = std::make_shared<TextureDatabase>(TextureDatabase());

    _window.setFramerateLimit(60);

    _manager->createEntityManager("GameScene");
    _textures->onCall("GameScene");
    _animations.onCall("GameScene");

    _timers.insert({"General", Timer(20)});
    _timers.insert({"Animation", Timer(125)});
    _manager->createSystem<ecs::Animate>(_manager);
    _manager->createSystem<ecs::Collider>(_manager);
    _manager->createSystem<ecs::ColliderReaction>(_manager);
    _manager->createSystem<ecs::Controll>(_manager);
    _manager->createSystem<ecs::Display>(_manager);
    _manager->createSystem<ecs::Fire>(_manager);
    _manager->createSystem<ecs::Input>(_manager);
    _manager->createSystem<ecs::Move>(_manager);

    size_t playerId = ecs::generateEntity(_manager->getEntityManager("GameScene"), "Player");
    ecs::Entity &player = _manager->getEntityManager("GameScene").getEntity(playerId);
    player.addComponent<ecs::AnimationFrame>();
    player.getComponent<ecs::Weapon>().setFireRate(250);

    for (auto &timer : _timers)
        timer.second.start();
}

TestGame::~TestGame() {}

void TestGame::createWalls()
{

}

void TestGame::checkEntitiesDrawable()
{
    for (auto &iterator : _manager->getEntityManager("GameScene").getEntities()) {
        ecs::Entity &entity = _manager->getEntityManager("GameScene").getEntity(iterator.first);
        if (entity.hasComponent<ecs::Type>() && entity.hasComponent<ecs::DrawableServerSide>()
            && !entity.hasComponent<ecs::DrawableClientSide>()) {
            entity.addComponent<ecs::DrawableClientSide>(
                _textures->getTexture(entity.getComponent<ecs::Type>().getEntityType()), 1);
            if (entity.hasComponent<ecs::AnimationFrame>())
                _manager->getSystem<ecs::Animate>().updateSprite(entity, _animations);
        }
        if (entity.hasComponent<ecs::Type>() && entity.hasComponent<ecs::AnimationFrame>()
            && entity.hasComponent<ecs::HitBox>()) {
            ecs::AnimationFrame &animationFrame = entity.getComponent<ecs::AnimationFrame>();
            ecs::HitBox &hitBox = entity.getComponent<ecs::HitBox>();
            Frame &frame = _animations.getFrame(entity.getComponent<ecs::Type>().getEntityType(),
                animationFrame.getAnimation(), animationFrame.getFrame());
            hitBox.setHitBox(frame[2], frame[3]);
        }
    }
}

void TestGame::update(const std::vector<ecs::RTypeEvent> &rTypeEvents)
{
    if (_timers.at("General").update()) {
        _manager->getSystem<ecs::Controll>().run("GameScene", rTypeEvents, _playerId);
        _manager->getSystem<ecs::Move>().run("GameScene");
        _manager->getSystem<ecs::Collider>().run("GameScene");
    }
    if (_timers.at("Animation").update()) {
        _timers.at("Animation").start();
        _manager->getSystem<ecs::Animate>().run("GameScene", _animations);
    }
}

void TestGame::run()
{
    sf::Event event;
    std::vector<ecs::RTypeEvent> rTypeEvents;
    EnemyWave wave;

    wave.spawn(20, _manager->getEntityManager("GameScene"));
    while (_window.isOpen()) {
        std::cout << _manager->getEntityManager("GameScene").getNumberEntities() << std::endl;
        this->checkEntitiesDrawable();
        _window.clear();
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            rTypeEvents = _manager->getSystem<ecs::Input>().getInput(event);
        }
        this->update(rTypeEvents);
        _manager->getSystem<ecs::Display>().run("GameScene", _window);
        _window.display();
    }
}
