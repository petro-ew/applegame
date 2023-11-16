#pragma once

#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Math.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include <iostream>
#include "UI.h"

namespace ApplesGame
{
    struct Game {
        Player player;
        UI ui;
        Apple apples[NUM_APPLES];
        Rock rocks[NUM_ROCKS];
        
        // Global game data
        int numEatenApples = 0;
        bool isGameFinished = false;
        float timeSinceGameFinish = 0.f;
        sf::RectangleShape background;
        // Resources
        sf::Texture playerTexture;
        
    };
    
    void RestartGame (Game &game);
    
    void InitGame (Game &game);
    
    void UpdateGame (Game &game, float deltaTime);
    
    void DrawGame (Game &game, sf::RenderWindow &window);
    
    void DeinializeGame (Game &game);
} // namespace ApplesGame