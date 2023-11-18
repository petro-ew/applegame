#include "Game.h"
#include <cassert>


namespace ApplesGame
{
    void RestartGame(Game &game)
    {
        InitPlayer(game.player, game);
        
        // Init apples
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            InitApple(game.apples[i], game);
        }
        
        // Init rocks
        for (int i = 0; i < NUM_ROCKS; ++i)
        {
            InitRock(game.rocks[i], game);
        }
        
        
        game.numEatenApples = 0;
        game.isGameFinished = false;
        game.timeSinceGameFinish = 0;
        
        initScoreText(game.ui, game);
        initGameOverText(game.ui, game);
    }
    
    void InitGame(Game &game)
    {
        try
        {
            game.ui.font.loadFromFile(RESOURCES_PATH + "/Fonts" + "/Roboto-Regular.ttf");
            game.ui.scoreTxt.setFont(game.ui.font);
            game.ui.gameOverText.setFont(game.ui.font);
        }
        catch (...)
        {
            std::cout << "не могу загрузить Roboto - Regular.ttf" << std::endl;
            exit(0);
        }
        assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "/Player.png"));
        assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "/Rock.png"));
        assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "/Apple.png"));
        assert(game.soundBufferApple.loadFromFile(RESOURCES_PATH + "/AppleEat.wav"));
        assert(game.soundBufferDeath.loadFromFile(RESOURCES_PATH + "/Death.wav"));
        
        game.soundApple.setBuffer(game.soundBufferApple);
        game.soundDeath.setBuffer(game.soundBufferDeath);
        
        game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        game.background.setFillColor(sf::Color::Black);
        game.background.setPosition(0.f, 0.f);
        initScoreText(game.ui, game);
        RestartGame(game);
    }
    
    void UpdateGame(Game &game, float deltaTime)
    {
        // Update game state
        if (!game.isGameFinished)
        {
            // Handle input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                game.player.direction = PlayerDirection::Right;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                game.player.direction = PlayerDirection::Up;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                game.player.direction = PlayerDirection::Left;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                game.player.direction = PlayerDirection::Down;
            }
            
            // Update player state
            switch (game.player.direction)
            {
                case PlayerDirection::Right:
                {
                    game.player.position.x += game.player.speed * deltaTime;
                    
                    
                    break;
                }
                case PlayerDirection::Up:
                {
                    
                    game.player.position.y -= game.player.speed * deltaTime;
                    
                    break;
                }
                case PlayerDirection::Left:
                {
                    
                    game.player.position.x -= game.player.speed * deltaTime;
                    
                    
                    break;
                }
                case PlayerDirection::Down:
                {
                    game.player.position.y += game.player.speed * deltaTime;
                    
                    break;
                }
            }
            
            // Find player collisions with apples
            for (int i = 0; i < NUM_APPLES; ++i)
            {
                if (IsCirclesCollide(game.player.position,
                                     PLAYER_SIZE / 2.f, game.apples[i].position, APPLE_SIZE / 2.f))
                {
                    updateAppleSpritePosition(i, game);
                    updateScoreText(game.ui, game);
                }
            }
            
            // Find player collisions with rocks
            for (int i = 0; i < NUM_ROCKS; ++i)
            {
                if (IsRectanglesCollide(game.player.position, {PLAYER_SIZE, PLAYER_SIZE}, game.rocks[i].position, {
                        ROCK_SIZE, ROCK_SIZE}))
                {
                    game.isGameFinished = true;
                    game.timeSinceGameFinish = 0.f;
                    game.soundDeath.play();
                }
            }
            
            // Check screen borders collision
            if (game.player.position.x - PLAYER_SIZE / 2.f < 0.f ||
                game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
                game.player.position.y - PLAYER_SIZE / 2.f < 0.f ||
                game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
            {
                game.isGameFinished = true;
                game.timeSinceGameFinish = 0.f;
                game.soundDeath.play();
            }
        }
        else
        {
            if (game.timeSinceGameFinish <= PAUSE_LENGTH)
            {
                game.timeSinceGameFinish += deltaTime;
                game.background.setFillColor(sf::Color::Red);
            }
            else
            {
                // Reset backgound
                game.background.setFillColor(sf::Color::Black);
                
                RestartGame(game);
            }
        }
    }
    
    void DrawGame(Game &game, sf::RenderWindow &window)
    {
        window.draw(game.background);
        //game.player.shape.setPosition(game.player.position.x, game.player.position.y);
        //window.draw(game.player.shape);
        if (game.player.direction == PlayerDirection::Right)
        {
            game.player.sprite.setRotation(0.f);
            DrawPlayer(game.player, window);
        }
        else if (game.player.direction == PlayerDirection::Left)
        {
            game.player.sprite.setRotation(180.f);
            DrawPlayer(game.player, window);
        }
        else if (game.player.direction == PlayerDirection::Up)
        {
            game.player.sprite.setRotation(270.f);
            DrawPlayer(game.player, window);
        }
        else if (game.player.direction == PlayerDirection::Down)
        {
            game.player.sprite.setRotation(90.f);
            DrawPlayer(game.player, window);
        }
        
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            game.apples[i].sprite.setPosition(game.apples[i].position.x, game.apples[i].position.y);
            window.draw(game.apples[i].sprite);
        }
        
        for (int i = 0; i < NUM_ROCKS; ++i)
        {
            game.rocks[i].sprite.setPosition(game.rocks[i].position.x, game.rocks[i].position.y);
            window.draw(game.rocks[i].sprite);
        }
        drawScoreText(game.ui, window);
        
        if (game.isGameFinished == true)
        {
            drawGameOverText(game.ui, window);
        }
    }
    
    void DeinializeGame(Game &game)
    {
    
    }
} // namespace ApplesGame