/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationDatabase
*/

#ifndef ANIMATIONDATABASE_HPP_
#define ANIMATIONDATABASE_HPP_

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

      private:
        std::unordered_map<std::string, Animations> _animationMap;
    };
} // namespace rtype

#endif /* !ANIMATIONDATABASE_HPP_ */
