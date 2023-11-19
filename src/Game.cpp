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
        
        initHelpDeskText(game.ui, false);
        initScoreText(game.ui, game);
        initGameOverText(game.ui);
    }
    
    void InitGame(Game &game)
    {
        /*
        try
        {
            game.ui.font.loadFromFile(RESOURCES_PATH + "/Fonts" + "/Roboto-Regular.ttf");
            }
        catch (...)
        {
            std::cout << "не могу загрузить Roboto - Regular.ttf" << std::endl;
            exit(0);
        }
         */
        assert(game.font.loadFromFile(RESOURCES_PATH + "/Fonts" + "/Roboto-Regular.ttf"));
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
        
        game.ui.scoreTxt.setFont(game.font);
        game.ui.gameOverText.setFont(game.font);
        game.ui.helpDesk.setFont(game.font);
        game.ui.muteText.setFont(game.font);
        initMuteText(game.ui, true);
        initScoreText(game.ui, game);
        initHelpDeskText(game.ui, false);
        RestartGame(game);
    }
    
    void UpdateGame(Game &game, float deltaTime)
    {
        // Update game state
        if (!game.isGameFinished)
        {
            // Handle input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
            {
                game.player.direction = PlayerDirection::Right;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                     (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
            {
                game.player.direction = PlayerDirection::Up;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
                     (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
            {
                game.player.direction = PlayerDirection::Left;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                     (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
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
                    UpdateAppleSpritePosition(i, game);
                    UpdateScoreText(game.ui, game);
                }
            }
            
            // Find player collisions with rocks
            for (int i = 0; i < NUM_ROCKS; ++i)
            {
                if (IsRectanglesCollide(game.player.position, {PLAYER_SIZE, PLAYER_SIZE}, game.rocks[i].position, {
                        ROCK_SIZE, ROCK_SIZE}))
                {
                    GameOver(game);
                }
            }
            
            // Check screen borders collision
            if (game.player.position.x - PLAYER_SIZE / 2.f < 0.f ||
                game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
                game.player.position.y - PLAYER_SIZE / 2.f < 0.f ||
                game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
            {
                GameOver(game);
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
        drawHelpDeskText(game.ui, window);
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
            DrawApple(i, game, window);
        }
        
        for (int i = 0; i < NUM_ROCKS; ++i)
        {
            game.rocks[i].sprite.setPosition(game.rocks[i].position.x, game.rocks[i].position.y);
            window.draw(game.rocks[i].sprite);
        }
        
        drawScoreText(game.ui, window);
        drawMuteText(game.ui, window);
        if (game.isGameFinished == true)
        {
            drawGameOverText(game.ui, window);
        }
        
        
    }
    
    void DeinializeGame(Game &game)
    {
    
    }
    
    void GameOver(Game &game)
    {
        game.isGameFinished = true;
        game.timeSinceGameFinish = 0.f;
        game.soundDeath.play();
    }
} // namespace ApplesGame