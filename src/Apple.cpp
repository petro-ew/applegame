#include "Apple.h"
#include "Game.h"

namespace ApplesGame
{
    void InitApple(Apple &apple, const struct Game &game)
    {
        apple.position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
        apple.sprite.setTexture(game.appleTexture);
        SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
        SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
        
        //apple.shape.setRadius (APPLE_SIZE / 2.f);
        //apple.shape.setFillColor (sf::Color::Green);
        //apple.shape.setOrigin (APPLE_SIZE / 2.f, APPLE_SIZE / 2.f);
        apple.sprite.setPosition(apple.position.x, apple.position.y);
    }
    
    void updateAppleSpritePosition(int i, struct Game &game)
    {
        game.apples[i].position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
        ++game.numEatenApples;
        game.soundApple.play();
        game.player.speed += ACCELERATION;
    }
} // namespace ApplesGame