#include "Game.h"
#include <cassert>


namespace ApplesGame
{
    void startPlayingState(Game &game)
    {
        setPlayerPosition(game.player, {SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f});
        setPlayerSpeed(game.player, INITIAL_SPEED);
        setPlayerDirection(game.player, PlayerDirection::Right);
        
        //Init Apples
        for (int i = 0; i < NUM_APPLES; i++)
        {
            setApplePosition(game.apples[i], getRandomPositionInRectangle(game.screenRect));
        }
        //Init Rocks
        for (int i = 0; i < NUM_ROCKS; i++)
        {
            setRockPosition(game.rocks[i], getRandomPositionInRectangle(game.screenRect));
        }
        game.numEatenApples = 0;
        game.isGameFinished = false;
        game.timeSinceGameFinish = 0;
        initMuteText(game.ui, true);
        initScoreText(game.ui, game);
        initHelpDeskText(game.ui, false);
        
    }
    
    void updatePlayingState(Game &game, float deltaTime)
    {
        // Handle input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            setPlayerDirection(game.player, PlayerDirection::Right);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            setPlayerDirection(game.player, PlayerDirection::Up);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            setPlayerDirection(game.player, PlayerDirection::Left);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            setPlayerDirection(game.player, PlayerDirection::Down);
        }
        
        
        updatePlayer(game.player, deltaTime);
        
        // Find player collisions with apples
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            if (doShapesCollide(getPlayerCollider(game.player), getAppleCollider(game.apples[i])))
            {
                setApplePosition(game.apples[i], getRandomPositionInRectangle(game.screenRect));
                ++game.numEatenApples;
                setPlayerSpeed(game.player, getPlayerSpeed(game.player) + ACCELERATION);
                game.soundApple.play();
                UpdateScoreText(game.ui, game);
            }
        }
        
        // Find player collisions with rocks
        for (int i = 0; i < NUM_ROCKS; ++i)
        {
            if (doShapesCollide(getPlayerCollider(game.player), getRockCollider(game.rocks[i])))
            {
                startGameOverState(game);
            }
        }
        
        // Check screen borders collision
        if (!doShapesCollide(getPlayerCollider(game.player), game.screenRect))
        {
            startGameOverState(game);
        }
        
    }
    
    void startGameOverState(Game &game)
    {
        game.isGameFinished = true;
        game.timeSinceGameFinish = 0.f;
        game.soundDeath.play();
    }
    
    void updateGameOverState(Game &game, float deltaTime)
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
            
            startPlayingState(game);
        }
    }
    
    void initGame(Game &game)
    {
        //Load resources
        assert(game.font.loadFromFile(RESOURCES_PATH + "/Fonts" + "/Roboto-Regular.ttf"));
        assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "/Player.png"));
        assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "/Rock.png"));
        assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "/Apple.png"));
        assert(game.soundBufferApple.loadFromFile(RESOURCES_PATH + "/AppleEat.wav"));
        assert(game.soundBufferDeath.loadFromFile(RESOURCES_PATH + "/Death.wav"));
        //Init Sounds
        game.soundApple.setBuffer(game.soundBufferApple);
        game.soundDeath.setBuffer(game.soundBufferDeath);
        // Init background
        game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
        game.background.setFillColor(sf::Color::Black);
        game.background.setPosition(0.f, 0.f);
        // Init texts
        game.ui.scoreTxt.setFont(game.font);
        game.ui.gameOverText.setFont(game.font);
        game.ui.helpDesk.setFont(game.font);
        game.ui.muteText.setFont(game.font);
        initMuteText(game.ui, true);
        initScoreText(game.ui, game);
        initHelpDeskText(game.ui, false);
        // Init game objects
        game.screenRect = {0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT};
        initPlayer(game.player, game);
        // Init apples
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            initApple(game.apples[i], game);
        }
        
        // Init rocks
        for (int i = 0; i < NUM_ROCKS; ++i)
        {
            initRock(game.rocks[i], game);
        }
        startPlayingState(game);
    }
    
    void updateGame(Game &game, float deltaTime)
    {
        // Update game state
        if (!game.isGameFinished)
        {
            updatePlayingState(game, deltaTime);
        }
        else
        {
            updateGameOverState(game, deltaTime);
        }
    }
    
    void drawGame(Game &game, sf::RenderWindow &window)
    {
        // Draw background
        window.draw(game.background);
        // Draw game objects
        drawPlayer(game.player, window);
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            drawApple(game.apples[i], window);
        }
        
        for (int i = 0; i < NUM_ROCKS; ++i)
        {
            drawRock(game.rocks[i], window);
        }
        // Draw texts
        drawScoreText(game.ui, window);
        drawMuteText(game.ui, window);
        
        if (!game.isGameFinished)
        {
            window.draw(game.ui.scoreTxt);
            drawHelpDeskText(game.ui, window);
            //window.draw(game.controlsHintText);
        }
        else
        {
            drawGameOverText(game.ui, window);
            //window.draw(game.gameOverText);
            //window.draw(game.gameOverScoreText);
        }
    }
    
    void deinializeGame(Game &game)
    {
    
    }
    
} // namespace ApplesGame