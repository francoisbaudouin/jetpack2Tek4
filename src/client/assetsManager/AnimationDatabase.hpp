/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationDatabase
*/

#ifndef ANIMATIONDATABASE_HPP_
#define ANIMATIONDATABASE_HPP_

#define DEFAULT "IDLE"

#include <array>
#include <string>
#include <vector>
#include <unordered_map>

namespace rtype
{
    using AnimationFrame = std::array<float, 4>;
    using Animation = std::vector<AnimationFrame>;
    using Animations = std::unordered_map<std::string, Animation>;

    class AnimationDatabase {
      public:
        AnimationDatabase();
        ~AnimationDatabase();

        void onCall(const std::string &sceneName);
        size_t getAnimationSize(const std::string &entityType, const std::string &animationType) const;
        Animation &getAnimation(const std::string &entityType, const std::string &animationType);
        AnimationFrame &getAnimationFrame(
            const std::string &entityType, const std::string &animationType, const size_t frameId);

      private:
        std::unordered_map<std::string, Animations> _animationMap;
    };
} // namespace rtype

#endif /* !ANIMATIONDATABASE_HPP_ */
