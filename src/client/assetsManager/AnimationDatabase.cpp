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
    Animation anim;
    AnimationFrame animFrame;
    size_t id = 0;
    size_t size;

    for (auto it : jsonFile) {
        if (id != 0)
            animFrame[id - 1] = it.second.get_value<float>();
        else
            size = it.second.get_value<size_t>();
        id++;
    }
    for (id = 0; id < size; id++) {
        anim.push_back(animFrame);
        animFrame[0] += animFrame[2];
    }
    return (anim);
}

Animations createEntityAnimations(const boost::property_tree::ptree &jsonFile)
{
    Animations anims;

    for (auto it2 : jsonFile) {
        for (auto it3 : it2.second) {
            anims.insert({it3.first, createAnimation(it3.second)});
        }
    }
    return (anims);
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
