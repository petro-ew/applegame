#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
    
    struct Apple
    {
        Position2D position;
        //float isAppleEaten = 0;
        //sf::CircleShape shape;
        sf::Sprite sprite;
    };
    struct Game;
    
    void initApple(Apple &apple, const struct Game &game);
    
    void updateAppleSpritePosition(int i, struct Game &game);
    
    void setApplePosition(Apple &apple, const Position2D &position);
    
    Circle getAppleCollider(const Apple &apple);
    
    //void DrawApple(int i, const struct Game &game, sf::RenderWindow &window);
    void drawApple(Apple &apple, sf::RenderWindow &window);
} // namespace ApplesGame