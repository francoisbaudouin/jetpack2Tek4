/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationDatabase
*/

#ifndef ANIMATIONDATABASE_HPP_
#define ANIMATIONDATABASE_HPP_

#define DEFAULT "Idle"

#include <array>
#include <string>
#include <vector>
#include <unordered_map>

namespace rtype
{
    using Frame = std::array<int, 4>;
    using Animation = std::vector<Frame>;
    using Animations = std::unordered_map<std::string, Animation>;

    class AnimationDatabase {
      public:
        AnimationDatabase();
        ~AnimationDatabase();
        /**
         * @brief Load the json files needed by the current scene and fill _animationMap for use
         *
         * @param sceneName : id of the current scene
         */
        void onCall(const std::string &sceneName);
        /**
         * @brief Get the size of the animation specified as parameter
         * 
         * @param entityType : type of the entity that refer to it's animation
         * @param animationType : type of the animation to check
         * @return size_t : size of the animation
         */
        size_t getAnimationSize(const std::string &entityType, const std::string &animationType) const;
        /**
         * @brief Get the animation at type of entity passed as parameter
         * 
         * @param entityType : type of the entity needed
         * @param animationType : type of the animation
         * @return Animation& : animation to return
         */
        Animation &getAnimation(const std::string &entityType, const std::string &animationType);
        /**
         * @brief Get the frame from the animation passed as parameter
         * 
         * @param entityType : type of the entity needing the aimation
         * @param animationType : type of the animation
         * @param frameId : id of the frame in the animation
         * @return Frame& : frame to return
         */
        Frame &getFrame(const std::string &entityType, const std::string &animationType, const size_t frameId);

      private:
        std::unordered_map<std::string, Animations> _animationMap;
    };
} // namespace rtype

#endif /* !ANIMATIONDATABASE_HPP_ */
