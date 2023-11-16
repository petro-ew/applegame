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
    
    
    void initScoreText (UI &ui, const Game &game)
    {
        try {
            ui.font.loadFromFile (RESOURCES_PATH + "/Fonts" + "/Roboto-Regular.ttf");
            ui.scoreTxt.setFont (ui.font);
        }
        catch (...) {
            cout << "не могу загрузить Roboto - Regular.ttf" << std::endl;
            exit (0);
        }
        ui.scoreTxt.setCharacterSize (24);
        ui.scoreTxt.setFillColor (sf::Color::Yellow);
        ui.scoreTxt.setString ("Monti strike: " + std::to_string (game.numEatenApples));
        ui.scoreTxt.setPosition (20.f, 20.f);
    }
    
    void drawScoreText (UI &ui, sf::RenderWindow &window)
    {
        window.draw (ui.scoreTxt);
    }
}