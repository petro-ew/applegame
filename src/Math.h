#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace sf
{
    class Sprite;
}

namespace ApplesGame
{
    
    struct Vector2D {
        float x = 0;
        float y = 0;
    };
    
    typedef Vector2D Position2D;
    
    Position2D GetRandomPositionInScreen(float screenWidth, float screenHeight);
    
    sf::Vector2f getCenterPositionInScreen(sf::RenderWindow &window);
    
    bool IsRectanglesCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size);
    
    bool IsCirclesCollide(Position2D circle1Position, float circle1Radius, Position2D circle2Position, float circle2Radius);
    
    void SetSpriteSize(sf::Sprite &sprite, float desiredWidth, float desireHeight);
    
    void SetSpriteRelativeOrigin(sf::Sprite &sprite, float originX, float originY);
    
} // namespace ApplesGame