//
// Created by petroew on 15.11.23.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <SFML/Graphics/Text.hpp>
#include "Math.h"

namespace ApplesGame
{
    
    struct UI {
        sf::Text scoreTxt;
        sf::Font font;
        sf::Text gameOverText;
        int scoreTextSize = 24;
        int gameOverTextSize = 120;
        Position2D position;
        
    };
    
    struct Game;
    
    void initScoreText(UI &ui, const struct Game &game);
    
    void updateScoreText(UI &ui, const struct Game &game);
    
    void drawScoreText(UI &ui, sf::RenderWindow &window);
    
    void initGameOverText(UI &ui, const struct Game &game);
    
    void drawGameOverText(UI &ui, sf::RenderWindow &window);
} // namespace ApplesGame