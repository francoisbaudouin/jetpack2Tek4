/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include "ecs/components/Drawable.hpp"
#include "client/Client.hpp"
#include "ecs/components/Position.hpp"
#include "ecs/components/Velocity.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/systems/Move.hpp"
#include "SFML/Graphics.hpp"
#include "ecs/enums/Event.hpp"
#include <iostream>

using namespace ecs;

int main(void)
{
    Entity ent(0);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("src/game/assets/vesso.png");
  
    ent.addComponent<ecs::Drawable>(ent.getId(), playerTexture);
    ent.addComponent<Position>(ent.getId(), 100, 100);
    ent.addComponent<Velocity>(ent.getId(), 0.01, 0);
    std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> entityMap;
    entityMap[0] = std::make_shared<ecs::Entity>(ent);

    Client client(entityMap);
    client.run();
    return (0);
}
