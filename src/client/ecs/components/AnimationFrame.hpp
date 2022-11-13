/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** AnimationFrame
*/

#ifndef ANIMATIONFRAME_HPP_
#define ANIMATIONFRAME_HPP_

#include "AComponent.hpp"

namespace ecs
{
    class AnimationFrame : public AComponent {
      public:
        /**
         * @brief Construct an AnimationFrame object and set the needed values
         *
         * @param entityId : id of the entity using this component
         * @param animation : name of the current animation
         * @param frame : id of the used frame in the current animation
         */
        AnimationFrame(const size_t entityId, const std::string &animation = "Idle", const size_t frame = 0);
        ~AnimationFrame();
        /**
         * @brief Get the name of the current animation
         *
         * @return std::string : name of the current animation
         */
        std::string getAnimation() const;
        /**
         * @brief Get the id of the frame
         *
         * @return size_t : id of the frame
         */
        size_t getFrame() const;
        /**
         * @brief Set the name of the current animation
         *
         * @param animation : name of the current animation
         */
        void setAnimation(const std::string &animation);
        /**
         * @brief Set the frame of the animation
         *
         * @param frame : frame of the animation
         */
        void setFrame(const size_t frame);

      private:
        std::string _animation;
        size_t _frame;
    };
} // namespace ecs

#endif /* !ANIMATIONFRAME_HPP_ */
