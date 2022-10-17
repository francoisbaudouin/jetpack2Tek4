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

Client::Client() : _manager(), _windowSize(std::make_pair<int, int>(640, 360)) ,_window(sf::VideoMode(_windowSize.first, _windowSize.second), "Client window")
{
    Ecs tmpEcs;
    _manager = std::make_shared<Ecs>(tmpEcs);

    _manager->addSystem<Controll>(_manager);
    _manager->addSystem<Display>(_manager);
    _manager->addSystem<Move>(_manager);
    _manager->addSystem<Input>(_manager);
    _manager->addSystem<Fire>(_manager);
    _manager->addSystem<Collider>(_manager);
    _manager->addSystem<ColliderReaction>(_manager);

    _tmpTexture.loadFromFile("src/game/assets/Character.png");
    _tmpTexture2.loadFromFile("src/game/assets/Peeper.png");
    _tmpTexture3.loadFromFile("src/game/assets/Parallax.png");

    //      PLAYER
    auto &player = _manager->createEntity();

    player.addComponent<Drawable>(_tmpTexture);
    player.addComponent<Position>(100, 100);
    player.addComponent<Weapon>(0.3, 0, WeaponType::CANON);
    player.addComponent<Velocity>(0, 0);
    player.addComponent<Type>(entityType::PLAYER);
    player.addComponent<HitBox>(64, 64);
    player.addComponent<Controllable>(Device::KeyBoardKey::Z, Device::KeyBoardKey::D, Device::KeyBoardKey::Q,
        Device::KeyBoardKey::S, Device::KeyBoardKey::F);

    //      ENNEMY
    auto &enemy = _manager->createEntity();

    enemy.addComponent<Drawable>(_tmpTexture2);
    enemy.addComponent<Position>(300, 100);
    enemy.addComponent<Velocity>(0, 0);
    enemy.addComponent<Type>(entityType::ENEMY);
    enemy.addComponent<HitBox>(32, 32);

    // background

    // auto &background = _manager->createEntity();
    // background.addComponent<Position>(0, 0);
    // background.addComponent<Drawable>(_tmpTexture3);
    // WALLS

    auto &wall1 = _manager->createEntity();
    wall1.addComponent<Position>(0, 0);
    wall1.addComponent<HitBox>(_windowSize.first, 1);
    wall1.addComponent<Type>(WALL);

    auto &wall2 = _manager->createEntity();
    wall2.addComponent<Position>(0, _windowSize.second);
    wall2.addComponent<HitBox>(_windowSize.first, 1);
    wall2.addComponent<Type>(WALL);

    auto &wall3 = _manager->createEntity();
    wall3.addComponent<Position>(0, 0);
    wall3.addComponent<HitBox>(1, _windowSize.second);
    wall3.addComponent<Type>(WALL);

    auto &wall4 = _manager->createEntity();
    wall4.addComponent<Position>(_windowSize.first, 0);
    wall4.addComponent<HitBox>(1, _windowSize.second);
    wall4.addComponent<Type>(WALL);

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
            _manager->getSystem<Controll>().run(_manager->getSystem<Input>().getInput(event), 0);
        }
        _manager->getSystem<Move>().run();
        _manager->getSystem<Collider>().run();
        _manager->getSystem<Display>().run(_window);
        _window.display();
    }
}