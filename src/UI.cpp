//
// Created by petroew on 15.11.23.
//
/*
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
        ui.scoreTxt.setString("Monti Strike: " + std::to_string(0));
        ui.scoreTxt.setPosition(20.f, 20.f);
    }

    void UpdateScoreText(UI &ui, const Game &game)
    {
        ui.scoreTxt.setString("Monti strike: " + std::to_string(game.numEatenApples));
    }

    void initGameOverText(UI &ui)
    {

        ui.gameOverText.setCharacterSize(ui.gameOverTextSize);
        ui.gameOverText.setFillColor(sf::Color::White);
        ui.gameOverText.setString("Game Over");
    }

    void initHelpDeskText(UI &ui, bool check)
    {
        ui.helpDesk.setCharacterSize(ui.scoreTextSize);
        ui.helpDesk.setFillColor(sf::Color::White);
        ui.helpDesk.setPosition(250.f, 20.f);
        if (check == true)
        {
            ui.helpDesk.setString("Move - wasd \n m - music off \n Esc - exit. \n h - help   ");
        }
        else
        {
            ui.helpDesk.setString("h - help");
        }
    }

    void initMuteText(UI &ui, bool check)
    {
        ui.muteText.setCharacterSize(ui.scoreTextSize);
        ui.muteText.setFillColor(sf::Color::Green);
        ui.muteText.setPosition(SCREEN_WIDTH - 140, SCREEN_HEIGHT - 40);
        if (check == false)
        {
            ui.muteText.setFillColor(sf::Color::Red);
            ui.muteText.setString("Sound - off");
        }
        else
        {
            ui.muteText.setString("Sound - on");
        }
    }

    void drawScoreText(UI &ui, sf::RenderWindow &window)
    {
        window.draw(ui.scoreTxt);
    }

    void drawGameOverText(UI &ui, sf::RenderWindow &window)
    {
        sf::Vector2f centerPos = getCenterPositionInScreen(window);
        ui.gameOverText.setPosition(
                centerPos.x - ui.gameOverText.getGlobalBounds().width / 2,
                centerPos.y - ui.gameOverTextSize / 2 - ui.gameOverText.getGlobalBounds().height / 2);
        window.draw(ui.gameOverText);
    }

    void drawHelpDeskText(UI &ui, sf::RenderWindow &window)
    {
        window.draw(ui.helpDesk);
    }

    void drawMuteText(UI &ui, sf::RenderWindow &window)
    {
        window.draw(ui.muteText);
    }


}
 */