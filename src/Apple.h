#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{

struct Apple
{
    Position2D position;
    sf::Sprite sprite;
};
struct Game;

void initApple(Apple& apple, const struct Game& game);

void updateAppleSpritePosition(int i, struct Game& game);

void setApplePosition(Apple& apple, const Position2D& position);

Circle getAppleCollider(const Apple& apple);

void drawApple(Apple& apple, sf::RenderWindow& window);
} // namespace ApplesGame