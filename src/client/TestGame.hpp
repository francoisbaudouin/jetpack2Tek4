/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** TestGame
*/

#ifndef TESTGAME_HPP_
#define TESTGAME_HPP_

#include "assetsManager/TextureDatabase.hpp"
#include "assetsManager/AnimationDatabase.hpp"

#include "game/Timer.hpp"
#include "ecs/Ecs.hpp"
#include "ecs/enums/event.hpp"

namespace rtype
{
    class TestGame {
      public:
        TestGame();
        ~TestGame();

        void createWalls();

        void checkEntitiesDrawable();

        void update(const std::vector<ecs::RTypeEvent> &rTypeEvents);

        void run();

      protected:
      private:
        size_t _playerId;
        sf::RenderWindow _window;
        AnimationDatabase _animations;
        std::shared_ptr<ecs::Ecs> _manager;
        std::shared_ptr<TextureDatabase> _textures;
        std::unordered_map<std::string, Timer> _timers;
    };
} // namespace rtype

#endif /* !TESTGAME_HPP_ */
