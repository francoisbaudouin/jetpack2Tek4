/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

namespace rtype
{
    class Timer {
        public:
            Timer(const int64_t delta = 100);
            ~Timer();

            void start();
            bool update();
        private:
            int64_t _delta;
            std::chrono::time_point<std::chrono::system_clock> _start;
    };
}

#endif /* !TIMER_HPP_ */
