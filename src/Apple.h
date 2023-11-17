#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
    
    struct Apple {
        Position2D position;
        //sf::CircleShape shape;
        sf::Sprite sprite;
    };
    struct Game;
    
    void InitApple (Apple &apple, const struct Game &game);
} // namespace ApplesGame