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

struct UI
{
    sf::Text scoreTxt;
    sf::Text gameOverText;
    sf::Text helpDesk;
    sf::Text muteText;
    int scoreTextSize = 24;
    int gameOverTextSize = 120;
    bool check_help = false;
    Position2D position;
};

struct Game;

void initScoreText(UI& ui, const struct Game& game);

void UpdateScoreText(UI& ui, const struct Game& game);

void initGameOverText(UI& ui);

void initHelpDeskText(UI& ui, bool check);

void initMuteText(UI& ui, bool check);

void drawScoreText(UI& ui, sf::RenderWindow& window);

void drawGameOverText(UI& ui, sf::RenderWindow& window);

void drawHelpDeskText(UI& ui, sf::RenderWindow& window);

void drawMuteText(UI& ui, sf::RenderWindow& window);

} // namespace ApplesGame