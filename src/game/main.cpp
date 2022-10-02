/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** main
*/

#include "Entity.hpp"
#include "components/Position.hpp"
#include "components/Drawable.hpp"
#include "systems/Display.hpp"

void test(Entity &ent)
{
  Display dis;

  dis.addData(ent);
  const std::vector<t_data> data = dis.getData();
  dis.clearData();

  std::cout << data.size() << std::endl;
  std::cout << data.begin()->id << std::endl;
  std::cout << data.begin()->pos[0] << " " << data.begin()->pos[1] << std::endl;
}

int main(void) 
{
  Entity ent(0);

  ent.addComponent<Position>();
  ent.addComponent<Drawable>();
  test(ent);
  return (0);
}
