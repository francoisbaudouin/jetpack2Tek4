/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Weapon
*/

#include "Weapon.hpp"
using namespace ecs;

Weapon::Weapon(const size_t entityId, float fireRate, float damage, WeaponType type)
    : AComponent(entityId), _fireRate(fireRate), _damage(damage), _type(type)
{
}

Weapon::~Weapon() {}

float Weapon::getFireRate() const { return _fireRate; }

float Weapon::getDamage() const { return _damage; }

WeaponType Weapon::getType() const { return _type; }

void Weapon::setFireRate(const float fireRate) { _fireRate = fireRate; }

void Weapon::setDamage(const float damage) { _damage = damage; }

void Weapon::setType(const WeaponType type) { _type = type; }
