/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include <iostream>
#include <utility>
#include "SFML/Graphics.hpp"
#include "client/Client.hpp"
#include "ecs/components/Controllable.hpp"
#include "ecs/components/Drawable.hpp"
#include "ecs/components/Position.hpp"
#include "ecs/components/Velocity.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/enums/event.hpp"
#include "ecs/enums/controlls.hpp"
#include "ecs/systems/Move.hpp"

using namespace ecs;

int main(void)
{
    Entity ent(0);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("src/game/assets/vesso.png");

    ent.addComponent<ecs::Drawable>(ent.getId(), playerTexture);
    ent.addComponent<Position>(ent.getId(), 100, 100);
    ent.addComponent<Velocity>(ent.getId(), 0, 0);
    ent.addComponent<Controllable>(ent.getId(),
        std::make_pair<Device::KeyBoardKey, Controlls>(Device::KeyBoardKey::Z, Controlls::UP),
        std::make_pair<Device::KeyBoardKey, Controlls>(Device::KeyBoardKey::D, Controlls::RIGHT),
        std::make_pair<Device::KeyBoardKey, Controlls>(Device::KeyBoardKey::Q, Controlls::LEFT),
        std::make_pair<Device::KeyBoardKey, Controlls>(Device::KeyBoardKey::S, Controlls::DOWN));
    std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> entityMap;
    entityMap[0] = std::make_shared<ecs::Entity>(ent);

    Client client(entityMap);
    client.run();
    return (0);
}
