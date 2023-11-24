#include "Player.h"
#include "Game.h"

/*
namespace ApplesGame
{
void initPlayer(Player& player, const struct Game& game)
{
    // Init player state
    player.position = {SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f};
    player.speed = INITIAL_SPEED;
    player.direction = PlayerDirection::Right;
    player.sprite.rotate(player.rotate);
    player.sprite.setScale(player.scalex, player.scaley);
    // Init player sprite texture
    player.sprite.setTexture(game.playerTexture);
    setSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
    setSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
}

void drawPlayer(Player& player, sf::RenderWindow& window)
{
    player.sprite.setPosition(player.position.x, player.position.y);
    //  Orient player sprite according to player direction
    if (player.direction == PlayerDirection::Left)
    {
        setSpriteSize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
        player.sprite.setRotation(0.f);
    }
    else
    {
        setSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
        player.sprite.setRotation((float)player.direction * -90.f);
    }
    window.draw(player.sprite);
}

void setPlayerDirection(Player& player, PlayerDirection direction)
{
    player.direction = direction;
}

void setPlayerPosition(Player& player, const Position2D& position)
{
    player.position = position;
}

void setPlayerSpeed(Player& player, float speed)
{
    player.speed = speed;
}

float getPlayerSpeed(const Player& player)
{
    return player.speed;
}

Rectangle getPlayerCollider(const Player& player)
{
    return {{player.position.x - PLAYER_SIZE / 2.f, player.position.y - PLAYER_SIZE / 2.f}, {PLAYER_SIZE, PLAYER_SIZE}};
}

void updatePlayer(Player& player, float deltaTime)
{
    // Update player state
    switch (player.direction)
    {
    case PlayerDirection::Right: {
        player.position.x += player.speed * deltaTime;
        break;
    }
    case PlayerDirection::Up: {
        player.position.y -= player.speed * deltaTime;
        break;
    }
    case PlayerDirection::Left: {
        player.position.x -= player.speed * deltaTime;
        break;
    }
    case PlayerDirection::Down: {
        player.position.y += player.speed * deltaTime;
        break;
    }
    }
}
} // namespace ApplesGame
 */