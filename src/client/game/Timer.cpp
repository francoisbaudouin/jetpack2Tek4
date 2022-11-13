/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Timer
*/

#include "Timer.hpp"

using namespace rtype;

Timer::Timer(const int64_t delta) : _delta(delta) {}

Timer::~Timer() {}

void Timer::start() { _start = std::chrono::system_clock::now(); }

bool Timer::update()
{
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

    return (std::chrono::duration_cast<std::chrono::milliseconds>(end - _start).count() >= _delta);
}
