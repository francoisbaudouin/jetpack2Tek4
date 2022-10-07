/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include "ecs/components/Position.hpp"
#include "ecs/components/Velocity.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/systems/Move.hpp"

namespace ecs
{
    void move(Entity &ent){
      std::unordered_map<size_t, std::shared_ptr<Entity>> map;
      map[ent.getId()] = std::make_shared<Entity>(ent);
      Move mo(map);

      mo.run();
    };

    void test()
    {
        Entity ent(0);
        ent.addComponent<Position>(ent.getId(), 3, 2);
        ent.addComponent<Velocity>(ent.getId(), -1, 1);
        auto &pos = ent.getComponent<Position>();

        move(ent);
        std::cout << pos.getEntityId() << " " << pos.getX() << " " << pos.getY() << std::endl;
    }
} // namespace ecs

int main(void)
{
    ecs::test();
    return (0);
}
