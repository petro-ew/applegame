//
// Created by petroew on 15.11.23.
//
#include "UI.h"
#include<iostream>
#include "Game.h"

namespace ApplesGame
{
    using namespace std;
    using std::cout;
    using std::string;
    using std::cin;
    using std::endl;
    
    
    void initScoreText(UI &ui, const Game &game)
    {
        
        ui.scoreTxt.setCharacterSize(ui.scoreTextSize);
        ui.scoreTxt.setFillColor(sf::Color::Yellow);
        ui.scoreTxt.setString("Monti strike: " + std::to_string(0));
        ui.scoreTxt.setPosition(20.f, 20.f);
    }
    
    void drawScoreText(UI &ui, sf::RenderWindow &window)
    {
        window.draw(ui.scoreTxt);
    }
    
    void initGameOverText(UI &ui, const struct Game &game)
    {
        
        ui.gameOverText.setCharacterSize(ui.gameOverTextSize);
        ui.gameOverText.setFillColor(sf::Color::White);
        ui.gameOverText.setString("Game Over");
    }
    
    void drawGameOverText(UI &ui, sf::RenderWindow &window)
    {
        sf::Vector2f centerPos = getCenterPositionInScreen(window);
        ui.gameOverText.setPosition(
                centerPos.x - ui.gameOverText.getGlobalBounds().width / 2,
                centerPos.y - ui.gameOverTextSize / 2 - ui.gameOverText.getGlobalBounds().height / 2);
        window.draw(ui.gameOverText);
    }
    
    void UpdateScoreText(UI &ui, const Game &game)
    {
        ui.scoreTxt.setString("Monti strike: " + std::to_string(game.numEatenApples));
    }
    
    
}