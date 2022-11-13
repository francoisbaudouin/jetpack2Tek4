/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Animate
*/

#ifndef ANIMATE_HPP_
#define ANIMATE_HPP_

#include "../../assetsManager/AnimationDatabase.hpp"
#include "ASystem.hpp"

namespace ecs
{
    class Animate : public ASystem {
      public:
        /**
         * @brief Animate will go to the animation database do update the textureRect of a sprite and update the frames
         * of the animation
         *
         * @param manager : shared_ptr to the ecs
         */
        Animate(std::shared_ptr<Ecs> &manager);
        ~Animate();
        /**
         * @brief will get the actual frame of the animation and update it based on the AnimationDatabase
         *
         * @param entity : entity needing the update
         * @param database : contains all the coordinates of the animations
         */
        void animateEntity(Entity &entity, rtype::AnimationDatabase &database);
        /**
         * @brief will update the texture rect of the sprite from the entity based on it's actual animation
         *
         * @param entity : entity needing the update
         * @param database : contains all the coordinates of the animations
         */
        void updateSprite(Entity &entity, rtype::AnimationDatabase &database);
        /**
         * @brief check all entities in the curent scene and update the ones needing animation
         *
         * @param sceneId : name of the actual scene
         * @param database : database of all animations
         */
        void run(const std::string &sceneId, rtype::AnimationDatabase &database);
        /**
         * @brief special animate function that is called when theres only button in scene
         *
         * @param sceneId : id of the current scene
         */
        void runButton(const std::string &sceneId);
        /**
         * @brief special animate function that is change the color of the text when selected
         *
         * @param sceneId : id of the current scene
         */
        void runSelectable(const std::string &sceneId);

      private:
    };
} // namespace ecs

#endif /* !ANIMATE_HPP_ */
