/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Test
*/

#include "Test.hpp"

#include "ecs/entity/EntityGenerator.hpp"
#include "ecs/components/DrawableClientSide.hpp"
#include "ecs/systems/Display.hpp"

using namespace rtype;

Test::Test() : _window(sf::VideoMode(640, 360), "Subaquatica")
{
    _manager = std::make_shared<ecs::Ecs>(ecs::Ecs());
    _textures = std::make_shared<TextureDatabase>(TextureDatabase());

    _manager->createEntityManager("Game");
    _manager->createSystem<ecs::Display>(_manager);
    _textures->onCall("Game");

    size_t id = ecs::generateEntity(_manager->getEntityManager("Game"), "Player");

    ecs::Entity &ent = _manager->getEntityManager("Game").getEntity(id);
    ent.addComponent<ecs::DrawableClientSide>(_textures->getTexture("Player"));
}

void Test::run()
{
    sf::Event event;
    // size_t messageLength = 0;

    while (_window.isOpen()) {
        _window.clear();
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _manager->getSystem<ecs::Display>().run("Game", _window);
        _window.display();
    }
}

Test::~Test() {}