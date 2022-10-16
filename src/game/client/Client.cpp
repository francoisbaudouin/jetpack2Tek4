/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Client
*/

#include "Client.hpp"
#include "../ecs/systems/Collider.hpp"
#include "../ecs/systems/ColliderReaction.hpp"
#include "../ecs/systems/Controll.hpp"
#include "../ecs/systems/Display.hpp"
#include "../ecs/systems/Fire.hpp"
#include "../ecs/systems/Input.hpp"
#include "../ecs/systems/Move.hpp"

#include "../ecs/components/Controllable.hpp"
#include "../ecs/components/Drawable.hpp"
#include "../ecs/components/HitBox.hpp"
#include "../ecs/components/Position.hpp"
#include "../ecs/components/Type.hpp"
#include "../ecs/components/Velocity.hpp"
#include "../ecs/components/Weapon.hpp"
#include "../ecs/enums/weapons.hpp"

using namespace ecs;

Client::Client() : _manager(), _window(sf::VideoMode(800, 600), "Client window")
{
    Ecs tmpEcs;
    _manager = std::make_shared<Ecs>(tmpEcs);
    _tmpTexture.loadFromFile("src/game/assets/Vesso.png");
    _tmpTexture2.loadFromFile("src/game/assets/agrgrlemechant.png");
    _manager->addSystem<Controll>(_manager);
    _manager->addSystem<Display>(_manager);
    _manager->addSystem<Move>(_manager);
    _manager->addSystem<Input>(_manager);
    _manager->addSystem<Fire>(_manager);
    _manager->addSystem<Collider>(_manager);
    _manager->addSystem<ColliderReaction>(_manager);

    //      PLAYER
    auto &player = _manager->createEntity();

    player.addComponent<Drawable>(_tmpTexture);
    player.addComponent<Position>(100, 100);
    player.addComponent<Velocity>(0.5, 0);
    player.addComponent<Weapon>(0.3, 0, WeaponType::CANON);
    player.addComponent<Type>(entityType::PLAYER);
    player.addComponent<HitBox>(32, 32);

    player.addComponent<Controllable>(Device::KeyBoardKey::Z, Device::KeyBoardKey::D, Device::KeyBoardKey::Q,
        Device::KeyBoardKey::S, Device::KeyBoardKey::F);

    //      ENNEMY
    auto &enemy = _manager->createEntity();

    enemy.addComponent<Drawable>(_tmpTexture2);
    enemy.addComponent<Position>(300, 100);
    enemy.addComponent<Velocity>(0, 0);
    enemy.addComponent<Type>(entityType::ENEMY);
    enemy.addComponent<HitBox>(32, 32);
}

Client::~Client() {}

// member function

void Client::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        _window.clear();
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            _manager->getSystem<Controll>().run(_manager->getSystem<Input>().getInput(event));
        }
        _manager->getSystem<Move>().run();
        _manager->getSystem<Collider>().run();
        _manager->getSystem<Display>().run(_window);
        _window.display();
    }
}