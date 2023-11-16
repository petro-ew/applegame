#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio/Sound.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
    
    struct Rock {
        Position2D position;
        //sf::RectangleShape shape;
        sf::Sprite sprite;
    };
    
    struct Game;
    
    void InitRock (Rock &rock, const Game &game);
} // namespace ApplesGame