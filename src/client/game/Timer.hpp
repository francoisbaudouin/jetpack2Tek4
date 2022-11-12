/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-arthur.richard
** File description:
** Timer
*/

#pragma once

#include <chrono>

namespace rtype
{
    class Timer {
        public:
            Timer(const size_t delta = 100);
            ~Timer();

            void start();
            bool update();
        private:
            size_t _delta;
            std::chrono::time_point<std::chrono::system_clock> _start;
    };
}
