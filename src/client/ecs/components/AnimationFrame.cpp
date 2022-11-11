/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationFrame
*/

#include "AnimationFrame.hpp"

using namespace ecs;

AnimationFrame::AnimationFrame(const size_t entityId, const std::string &animation, const size_t frame)
    : AComponent(entityId), _animation(animation), _frame(frame)
{
}

AnimationFrame::~AnimationFrame() {}

std::string AnimationFrame::getAnimation() const { return (_animation); }

size_t AnimationFrame::getFrame() const { return (_frame); }

void AnimationFrame::setAnimation(const std::string &animation) {_animation = animation; }

void AnimationFrame::setFrame(const size_t frame) {_frame = frame; }
