#include "Rock.h"
#include "Game.h"

namespace ApplesGame
{
    
    
    void initRock(Rock &rock, const Game &game)
    {
        //rock.position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
        
        rock.sprite.setTexture(game.rockTexture);
        setSpriteSize(rock.sprite, ROCK_SIZE, ROCK_SIZE);
        setSpriteRelativeOrigin(rock.sprite, 0.5f, 0.5f);
        
        //rock.shape.setSize(sf::Vector2f(ROCK_SIZE, ROCK_SIZE));
        //rock.shape.setFillColor(sf::Color::White);
        //rock.shape.setOrigin(ROCK_SIZE / 2.f, ROCK_SIZE / 2.f);
        //rock.sprite.setPosition(rock.position.x, rock.position.y);
    }
    
    void setRockPosition(Rock &rock, const Position2D &position)
    {
        rock.position = position;
    }
    
    Rectangle getRockCollider(const Rock &rock)
    {
        return {{rock.position.x - ROCK_SIZE / 2.f, rock.position.y - ROCK_SIZE / 2.f},
                {ROCK_SIZE, ROCK_SIZE}};
    }
    
    void drawRock(Rock &rock, sf::RenderWindow &window)
    {
        rock.sprite.setPosition(rock.position.x, rock.position.y);
        window.draw(rock.sprite);
    }
    
} // namespace ApplesGame