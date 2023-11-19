#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Constants.h"
#include "Math.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "UI.h"

namespace ApplesGame
{
    struct Game
    {
        Rectangle screenRect;
        Player player;
        UI ui;
        Apple apples[NUM_APPLES];
        Rock rocks[NUM_ROCKS];
        // Global game data
        int numEatenApples = 0;
        bool isGameFinished = false;
        float timeSinceGameFinish = 0.f;
        // Resources
        sf::Font font;
        sf::Texture playerTexture;
        sf::Texture rockTexture;
        sf::Texture appleTexture;
        sf::SoundBuffer soundBufferApple;
        sf::SoundBuffer soundBufferDeath;
        //Game objects
        sf::Sound soundDeath;
        sf::Sound soundApple;
        sf::RectangleShape background;
    };
    
    void initGame(Game &game);
    
    void updateGame(Game &game, float deltaTime);
    
    void startPlayingState(Game &game);
    
    void updatePlayingState(Game &game, float deltaTime);
    
    void startGameOverState(Game &game);
    
    void updateGameOverState(Game &game, float deltaTime);
    
    void drawGame(Game &game, sf::RenderWindow &window);
    
    void deinializeGame(Game &game);
} // namespace ApplesGame