/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationDatabase
*/

#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "AnimationDatabase.hpp"
#include "TextureDatabase.hpp"

using namespace rtype;

AnimationDatabase::AnimationDatabase() : _animationMap() {}

AnimationDatabase::~AnimationDatabase() {}

Animation createAnimation(const boost::property_tree::ptree &jsonFile)
{
    Animation animation;
    AnimationFrame animationFrame;
    size_t id = 0;
    size_t size;

    for (auto iterator : jsonFile) {
        if (id != 0)
            animationFrame[id - 1] = iterator.second.get_value<float>();
        else
            size = iterator.second.get_value<size_t>();
        id++;
    }
    for (id = 0; id < size; id++) {
        animation.push_back(animationFrame);
        animationFrame[0] += animationFrame[2];
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
    boost::property_tree::ptree jsonFile;
    std::string path("assets/configFiles/" + sceneName + "/Animations.json");
    std::string scenePath = fileTraduction(path);
    boost::property_tree::read_json(scenePath, jsonFile);
    std::vector<std::string> strs;

    _animationMap.clear();
    for (auto iterator : jsonFile) {
        _animationMap.insert({iterator.first, createEntityAnimations(iterator.second)});
    }
}

size_t AnimationDatabase::getAnimationSize(const std::string &entityType, const std::string &animationType) const
{
    return (_animationMap.at(entityType).at(animationType).size());
}

Animation &AnimationDatabase::getAnimation(const std::string &entityType, const std::string &animationType)
{
    return (_animationMap.at(entityType).at(animationType));
}

AnimationFrame &AnimationDatabase::getAnimationFrame(
    const std::string &entityType, const std::string &animationType, const size_t frameId)
{
    return (_animationMap.at(entityType).at(animationType).at(frameId));
}
