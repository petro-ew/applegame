#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{

enum class PlayerDirection
{
    Right = 0,
    Up,
    Left,
    Down
};

struct Player
{
    Position2D position;
    float speed = INITIAL_SPEED;
    PlayerDirection direction = PlayerDirection::Right;
    sf::Sprite sprite;
    float rotate = 0.f;
    float scalex = 1.f;
    float scaley = 1.f;
};

struct Game;

void initPlayer(Player& player, const struct Game& game);

void setPlayerDirection(Player& player, PlayerDirection direction);

void setPlayerPosition(Player& player, const Position2D& position);

void setPlayerSpeed(Player& player, float);

float getPlayerSpeed(const Player& player);

Rectangle getPlayerCollider(const Player& player);

void updatePlayer(Player& player, float deltaTime);

void drawPlayer(Player& player, sf::RenderWindow& window);
} // namespace ApplesGame