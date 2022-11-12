/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationDatabase
*/

#include <iostream>

#include "../ecs/exceptions/Exception.hpp"
#include "AnimationDatabase.hpp"
#include "TextureDatabase.hpp"
#include "fileOpener.hpp"

using namespace rtype;

AnimationDatabase::AnimationDatabase() : _animationMap() {}

AnimationDatabase::~AnimationDatabase() {}

Animation createAnimation(const boost::property_tree::ptree &jsonFile)
{
    Animation animation;
    Frame frame;
    size_t id = 0;
    size_t size = 0;

    for (auto iterator : jsonFile) {
        if (id != 0)
            frame[id - 1] = iterator.second.get_value<int>();
        else
            size = iterator.second.get_value<size_t>();
        id++;
    }
    for (id = 0; id < size; id++) {
        animation.push_back(frame);
        frame[0] += frame[2];
    }
    return (animation);
}

Animations createEntityAnimations(const boost::property_tree::ptree &jsonFile)
{
    Animations animations;

    for (auto iterator : jsonFile) {
        for (auto iterator2 : iterator.second) {
            animations.insert({iterator2.first, createAnimation(iterator2.second)});
        }
    }
    return (animations);
}

void AnimationDatabase::onCall(const std::string &sceneName)
{
    std::string path("assets/configFiles/" + sceneName + "/Animations.json");
    boost::property_tree::ptree jsonFile = openJsonFile(path);

    _animationMap.clear();
    for (auto iterator : jsonFile) {
        _animationMap.insert({iterator.first, createEntityAnimations(iterator.second)});
    }
}

size_t AnimationDatabase::getAnimationSize(const std::string &entityType, const std::string &animationType) const
{
    if (!_animationMap.contains(entityType))
        throw ecs::TypeNotInAnimationDataBase(entityType);
    if (!_animationMap.at(entityType).contains(animationType))
        throw ecs::WrongAnimationCalled(entityType, animationType);
    return (_animationMap.at(entityType).at(animationType).size());
}

Animation &AnimationDatabase::getAnimation(const std::string &entityType, const std::string &animationType)
{
    if (!_animationMap.contains(entityType))
        throw ecs::TypeNotInAnimationDataBase(entityType);
    if (!_animationMap.at(entityType).contains(animationType))
        throw ecs::WrongAnimationCalled(entityType, animationType);
    return (_animationMap.at(entityType).at(animationType));
}

Frame &AnimationDatabase::getFrame(
    const std::string &entityType, const std::string &animationType, const size_t frameId)
{
    size_t size = 0;
    if (!_animationMap.contains(entityType))
        throw ecs::TypeNotInAnimationDataBase(entityType);
    if (!_animationMap.at(entityType).contains(animationType))
        throw ecs::WrongAnimationCalled(entityType, animationType);
    size = _animationMap.at(entityType).at(animationType).size();
    if (_animationMap.at(entityType).at(animationType).size() < frameId)
        throw ecs::AnimationFrameOutOfRange(entityType, animationType, size, frameId);
    return (_animationMap.at(entityType).at(animationType).at(frameId));
}
