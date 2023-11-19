#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio/Sound.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
    
    struct Rock
    {
        Position2D position;
        //sf::RectangleShape shape;
        sf::Sprite sprite;
    };
    
    struct Game;
    
    void initRock(Rock &rock, const Game &game);
    
    void setRockPosition(Rock &rock, const Position2D &position);
    
    void drawRock(Rock &rock, sf::RenderWindow &window);
    
    Rectangle getRockCollider(const Rock &rock);
} // namespace ApplesGame