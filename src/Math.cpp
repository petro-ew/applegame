#include "Math.h"
#include <cstdlib>
#include <cmath>
#include <SFML/Graphics.hpp>
//gcc -c -std=c++20 -fmodules-ts  *.cpp
//g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

namespace ApplesGame
{
    Position2D getRandomPositionInRectangle(const Rectangle &rect)
    {
        Position2D result;
        result.x = rand() / (float) RAND_MAX * rect.size.x + rect.position.x;
        result.y = rand() / (float) RAND_MAX * rect.size.y + rect.position.y;
        return result;
    }
    
    
    Position2D getRandomPositionInScreen(float screenWidth, float screenHeight)
    {
        Position2D result;
        result.x = rand() / (float) RAND_MAX * screenWidth;
        result.y = rand() / (float) RAND_MAX * screenHeight;
        return result;
    }
    
    bool isRectanglesCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size)
    {
        float dx = (float) fabs(rect1Position.x - rect2Position.x);
        float dy = (float) fabs(rect1Position.y - rect2Position.y);
        return (dx <= (rect1Size.x + rect2Size.x) / 2.f && dy <= (rect1Size.y + rect2Size.y) / 2.f);
    }
    
    bool isCirclesCollide(Position2D circle1Position, float circle1Radius, Position2D circle2Position, float circle2Radius)
    {
        float squareDistance = (circle1Position.x - circle2Position.x) * (circle1Position.x - circle2Position.x) +
                               (circle1Position.y - circle2Position.y) * (circle1Position.y - circle2Position.y);
        float squareRadiusSum = (circle1Radius + circle2Radius) * (circle1Radius + circle2Radius);
        return squareDistance <= squareRadiusSum;
    }
    
    void setSpriteSize(sf::Sprite &sprite, float desiredWidth, float desireHeight)
    {
        sf::FloatRect spriteRect = sprite.getLocalBounds();
        sf::Vector2f scale = {desiredWidth / spriteRect.width, desireHeight / spriteRect.height};
        sprite.setScale(scale);
    }
    
    void setSpriteRelativeOrigin(sf::Sprite &sprite, float originX, float originY)
    {
        sf::FloatRect spriteRect = sprite.getLocalBounds();
        sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
    }
    
    sf::Vector2f getCenterPositionInScreen(sf::RenderWindow &window)
    {
        sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2);
        return centerPos;
    }
    
    bool doShapesCollide(const Rectangle &rect1, const Rectangle &rect2)
    {
        return rect1.position.x < rect2.position.x + rect2.size.x &&
               rect1.position.x + rect1.size.x > rect2.position.x &&
               rect1.position.y < rect2.position.y + rect2.size.y &&
               rect1.position.y + rect1.size.y > rect2.position.y;
    }
    
    bool doShapesCollide(const Circle &circle1, const Circle &circle2)
    {
        float dx = circle1.position.x - circle2.position.x;
        float dy = circle1.position.y - circle2.position.y;
        float distance = sqrt(dx * dx + dy * dy);
        return distance < circle1.radius + circle2.radius;
    }
    
    bool doShapesCollide(const Rectangle &rect, const Circle &circle)
    {
        //const int &(*min)(const int &, const int &) = std::min<int>;
        float dx = circle.position.x -
                   std::max(rect.position.x, std::ranges::min(circle.position.x, rect.position.x + rect.size.x));
        float dy = circle.position.y -
                   std::max(rect.position.y, std::ranges::min(circle.position.y, rect.position.y + rect.size.y));
        return (dx * dx + dy * dy) < (circle.radius * circle.radius);
    }
    
} // namespace ApplesGame