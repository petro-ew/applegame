//
// Created by petroew on 23.11.23.
//

/*

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <cassert>
#include "Constants.h"

#ifndef APPLEGAME_MAINMENU_H
#define APPLEGAME_MAINMENU_H

struct mainMenu
{
    sf::Texture menuStartTexture;
    sf::Texture menuStartFocusTexture;
    sf::Texture menuExitTexture;
    sf::Texture menuExitFocusTexture;
    sf::Texture menuHelpTexture;
    sf::Texture menuHelpFocusTexture;
    sf::Texture menuBackgroundTexture;
    sf::Texture checkBoxTexture;
    sf::Texture checkBoxOnTexture;
    sf::Texture checkBoxDescriptionTexture;

    // sf::RectangleShape checkBox1; // с конечным числом яблок
    // sf::RectangleShape checkBox2; // с бесконечным числом яблок
    // sf::RectangleShape checkBox3; // с ускорением движения игрока после поедания яблока
    // sf::RectangleShape checkBox4; // без ускорения
    sf::Music musicMenuBack;

    sf::Sprite menuStartSprite;
    sf::Sprite menuStartFocusSprite;
    sf::Sprite menuExitSprite;
    sf::Sprite menuExitFocusSprite;
    sf::Sprite menuHelpSprite;
    sf::Sprite menuHelpFocusSprite;
    sf::Sprite menuBackgroundSprite;
    sf::Sprite checkBoxSprite;
    sf::Sprite checkBoxOnSprite;
    sf::Sprite checkBoxDescriptionSprite;
};

// struct startButton
//{

//};

void menuInit(mainMenu& main_menu, sf::RenderWindow& window)
{
    assert(main_menu.menuBackgroundTexture.loadFromFile("Resources/Menu/Screen_background.png"));

    assert(main_menu.menuStartTexture.loadFromFile("Resources/Menu/Screen_start.png"));
    assert(main_menu.menuStartFocusTexture.loadFromFile("Resources/Menu/Screen_start_frame.png"));
    assert(main_menu.menuExitTexture.loadFromFile("Resources/Menu/Screen_exit.png"));
    assert(main_menu.menuExitFocusTexture.loadFromFile("Resources/Menu/Screen_exit_frame.png"));
    assert(main_menu.menuHelpTexture.loadFromFile("Resources/Menu/Screen_help.png"));
    assert(main_menu.menuHelpFocusTexture.loadFromFile("Resources/Menu/Screen_help_frame.png"));

    assert(main_menu.checkBoxTexture.loadFromFile("Resources/Menu/off.png"));
    assert(main_menu.checkBoxOnTexture.loadFromFile("Resources/Menu/on.png"));
    assert(main_menu.checkBoxDescriptionTexture.loadFromFile("Resources/Menu/Screen_block.png"));

    assert(main_menu.musicMenuBack.openFromFile("Resources/Menu/menu1.wav"));

    main_menu.musicMenuBack.setLoop(true);
    main_menu.musicMenuBack.setVolume(50);

    main_menu.menuBackgroundSprite.setTexture(main_menu.menuBackgroundTexture);

    main_menu.menuStartSprite.setTexture(main_menu.menuStartTexture);
    main_menu.menuStartFocusSprite.setTexture(main_menu.menuStartFocusTexture);
    main_menu.menuExitSprite.setTexture(main_menu.menuExitTexture);
    main_menu.menuExitFocusSprite.setTexture(main_menu.menuExitFocusTexture);
    main_menu.menuHelpSprite.setTexture(main_menu.menuHelpTexture);
    main_menu.menuHelpFocusSprite.setTexture(main_menu.menuHelpFocusTexture);
    main_menu.checkBoxDescriptionSprite.setTexture(main_menu.checkBoxDescriptionTexture);

    main_menu.menuBackgroundSprite.setPosition(0, 0);
    main_menu.menuStartSprite.setPosition(100, 470);
    main_menu.menuHelpSprite.setPosition(100, 565);
    main_menu.menuExitSprite.setPosition(100, 659);
    main_menu.checkBoxDescriptionSprite.setPosition(870, 120);
}

void menuButton(sf::Sprite sprite, sf::Texture texture, sf::Vector2f pos)
{
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    // sprite.setColor(sf::Color(0, 0, 0));
}

void menu(mainMenu& main_menu, sf::RenderWindow& window)
{
    main_menu.musicMenuBack.play();
    bool isMenu = 1;
    int menuNum = 0;
    while (isMenu)
    {

        menuButton(main_menu.menuStartSprite, main_menu.menuStartTexture);
        // main_menu.menuStartSprite.setColor(sf::Color::White);
        main_menu.menuExitSprite.setColor(sf::Color::White);
        main_menu.menuHelpSprite.setColor(sf::Color::White);
        menuNum = 0;
        // window.clear(sf::Color(129, 181, 221));
        window.clear();

        if (sf::IntRect(100, 470, 408, 98).contains(sf::Mouse::getPosition(window)))
        {
            // main_menu.menuStartSprite.setColor(sf::Color::Red);
            menuButton(main_menu.menuStartSprite, main_menu.menuStartFocusTexture);
            menuNum = 1;
        }
        if (sf::IntRect(100, 565, 408, 98).contains(sf::Mouse::getPosition(window)))
        {
            main_menu.menuHelpSprite.setColor(sf::Color::Red);
            menuNum = 2;
        }
        if (sf::IntRect(100, 659, 408, 98).contains(sf::Mouse::getPosition(window)))
        {
            main_menu.menuExitSprite.setColor(sf::Color::Red);
            menuNum = 3;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1)
                isMenu = false; // если нажали первую кнопку, то выходим из меню
            if (menuNum == 2)
            {
                window.draw(main_menu.menuHelpSprite);
                window.display();
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    ;
            }
            if (menuNum == 3)
            {
                window.close();
                isMenu = false;
            }
        }

        window.draw(main_menu.menuBackgroundSprite);
        window.draw(main_menu.menuStartSprite);
        window.draw(main_menu.menuHelpSprite);
        window.draw(main_menu.menuExitSprite);
        window.draw(main_menu.checkBoxDescriptionSprite);

        window.display();
    }
}
#endif // APPLEGAME_MAINMENU_H
*/