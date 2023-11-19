#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace sf
{
    class Sprite;
}

namespace ApplesGame
{
    struct Vector2D
    {
        float x = 0;
        float y = 0;
    };
    
    typedef Vector2D Position2D;
    
    struct Rectangle
    {
        Position2D position; //top left corner coordinate
        Vector2D size;
    };
    
    struct Circle
    {
        Position2D position; //center coordinate
        float radius;
    };
    
    bool doShapesCollide(const Rectangle &rect1, const Rectangle &rect2);
    
    bool doShapesCollide(const Circle &circle1, const Circle &circle2);
    
    bool doShapesCollide(const Rectangle &rect, const Circle &circle);
    
    Position2D getRandomPositionInRectangle(const Rectangle &rect);
    
    Position2D getRandomPositionInScreen(float screenWidth, float screenHeight);
    
    sf::Vector2f getCenterPositionInScreen(sf::RenderWindow &window);
    
    bool isRectanglesCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size);
    
    bool isCirclesCollide(Position2D circle1Position, float circle1Radius, Position2D circle2Position, float circle2Radius);
    
    void setSpriteSize(sf::Sprite &sprite, float desiredWidth, float desireHeight);
    
    void setSpriteRelativeOrigin(sf::Sprite &sprite, float originX, float originY);
    
} // namespace ApplesGame