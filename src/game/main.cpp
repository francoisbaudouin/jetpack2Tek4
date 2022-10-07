/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include "ecs/components/Drawable.hpp"
#include "client/Client.hpp"
#include "ecs/entity/Entity.hpp"

namespace ecs
{
    void test() { Entity ent(0); }
} // namespace ecs

int main(void)
{
    ecs::Entity test(0);
    //test.addComponent<ecs::Drawable>();
    std::unordered_map<size_t, std::shared_ptr<ecs::Entity>> _entityMap;
    _entityMap[0] = std::make_shared<ecs::Entity>(test);

    Client client(_entityMap);
    client.run();
    return (0);
}
