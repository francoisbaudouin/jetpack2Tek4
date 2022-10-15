/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Weapon
*/

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "../enums/weapons.hpp"
#include "AComponent.hpp"

namespace ecs
{
    class Weapon : public AComponent {
      public:
      /**
       * @brief Construct a new Weapon component
       * 
       * @param entityId id of the linked entity
       * @param fireRate weapon's fireRate 
       * @param damage weapon's damage
       * @param type weapon's type
       */
        Weapon(const size_t entityId, float fireRate, float damage, WeaponType type);
        ~Weapon();
        /**
         * @brief Get the Fire Rate of the weapon
         * 
         * @return float  fireRate of the weapon
         */
        float getFireRate() const;
        /**
         * @brief Get the Damage of the weapon
         * 
         * @return float Damage of the weapon
         */
        float getDamage() const;
        /**
         * @brief Get the type of the weapon
         * 
         * @return WeaponType type of the weapon
         */
        WeaponType getType() const;

      protected:
      private:
        float _fireRate;
        float _damage;
        WeaponType _type;
    };
} // namespace ecs

#endif /* !WEAPON_HPP_ */
