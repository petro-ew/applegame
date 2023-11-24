#include "Apple.h"
#include "Game.h"
#include "Math.h"

/*
namespace ApplesGame
{
void initApple(Apple& apple, const struct Game& game)
{
    apple.position = getRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
    apple.sprite.setTexture(game.appleTexture);
    setSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
    setSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
}

void updateAppleSpritePosition(int i, struct Game& game)
{
    game.apples[i].position = getRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
    ++game.numEatenApples;
    game.soundApple.play();
    game.player.speed += ACCELERATION;
}

void drawApple(Apple& apple, sf::RenderWindow& window)
{
    apple.sprite.setPosition(apple.position.x, apple.position.y);
    window.draw(apple.sprite);
}

Circle getAppleCollider(const Apple& apple)
{
    return {apple.position, APPLE_SIZE / 2.f};
}

void setApplePosition(Apple& apple, const Position2D& position)
{
    apple.position = position;
}
} // namespace ApplesGame
 */