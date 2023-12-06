//
// Created by petroew on 01.12.23.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <cassert>
#include "Constants.h"
#include "Math.h"

#ifndef APPLEGAME_MAINMENU_H
#define APPLEGAME_MAINMENU_H
namespace ApplesGame
{
struct checkBox
{
    // Position2D position;
    sf::Sprite sprite;
};
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
    checkBox chBox[4];
    sf::Sprite menuStartSprite;
    sf::Sprite menuStartFocusSprite;
    sf::Sprite menuExitSprite;
    sf::Sprite menuExitFocusSprite;
    sf::Sprite menuHelpSprite;
    sf::Sprite menuHelpFocusSprite;
    sf::Sprite menuBackgroundSprite;
    sf::Sprite checkBoxSprite;
    sf::Sprite checkBoxOnSprite;
    sf::Sprite checkBoxSpriteTwo;
    sf::Sprite checkBoxOnSpriteTwo;
    sf::Sprite checkBoxDescriptionSprite;
    Position2D posMenuStartButton;
    Position2D posMenuExitButton;
    Position2D posMenuHelpButton;
};

void menuInit(mainMenu& main_menu, sf::RenderWindow& window)
{
    assert(main_menu.menuBackgroundTexture.loadFromFile("Resources/Menu/Screen_1.png"));

    assert(main_menu.menuStartTexture.loadFromFile("Resources/Menu/Screen_start.png"));
    assert(main_menu.menuStartFocusTexture.loadFromFile("Resources/Menu/Screen_start_frame.png"));
    assert(main_menu.menuExitTexture.loadFromFile("Resources/Menu/Screen_exit.png"));
    assert(main_menu.menuExitFocusTexture.loadFromFile("Resources/Menu/Screen_exit_frame.png"));
    assert(main_menu.menuHelpTexture.loadFromFile("Resources/Menu/Screen_help.png"));
    assert(main_menu.menuHelpFocusTexture.loadFromFile("Resources/Menu/Screen_help_frame.png"));

    assert(main_menu.checkBoxTexture.loadFromFile("Resources/Menu/off.png"));
    assert(main_menu.checkBoxOnTexture.loadFromFile("Resources/Menu/on.png"));

    assert(main_menu.musicMenuBack.openFromFile("Resources/Menu/menu1.wav"));

    main_menu.musicMenuBack.setLoop(true);
    main_menu.musicMenuBack.setVolume(50);

    main_menu.menuBackgroundSprite.setTexture(main_menu.menuBackgroundTexture);
    // main_menu.checkBoxDescriptionSprite.set main_menu.menuStartSprite.setTexture(main_menu.menuStartTexture);
    main_menu.menuStartFocusSprite.setTexture(main_menu.menuStartFocusTexture);

    main_menu.menuExitSprite.setTexture(main_menu.menuExitTexture);
    main_menu.menuExitFocusSprite.setTexture(main_menu.menuExitFocusTexture);

    main_menu.menuHelpSprite.setTexture(main_menu.menuHelpTexture);
    main_menu.menuHelpFocusSprite.setTexture(main_menu.menuHelpFocusTexture);

    main_menu.checkBoxOnSprite.setTexture(main_menu.checkBoxOnTexture);
    main_menu.checkBoxOnSpriteTwo.setTexture(main_menu.checkBoxOnTexture);

    main_menu.posMenuStartButton.x = 100.f;
    main_menu.posMenuStartButton.y = 470.f;

    main_menu.posMenuExitButton.x = 100.f;
    main_menu.posMenuExitButton.y = 659.f;

    main_menu.posMenuHelpButton.x = 100.f;
    main_menu.posMenuHelpButton.y = 565.f;

    main_menu.checkBoxSprite.setPosition(870, 120);
    main_menu.checkBoxOnSpriteTwo.setPosition(870, 500);
    main_menu.checkBoxOnSprite.setPosition(870, 147);

    main_menu.menuBackgroundSprite.setPosition(0, 0);

    main_menu.menuStartSprite.setPosition(main_menu.posMenuStartButton.x, main_menu.posMenuStartButton.y);
    main_menu.menuHelpSprite.setPosition(main_menu.posMenuHelpButton.x, main_menu.posMenuHelpButton.y);
    main_menu.menuExitSprite.setPosition(main_menu.posMenuExitButton.x, main_menu.posMenuExitButton.y);

    main_menu.menuStartFocusSprite.setPosition(main_menu.posMenuStartButton.x, main_menu.posMenuStartButton.y);
    main_menu.menuHelpFocusSprite.setPosition(main_menu.posMenuHelpButton.x, main_menu.posMenuHelpButton.y);
    main_menu.menuExitSprite.setPosition(main_menu.posMenuExitButton.x, main_menu.posMenuExitButton.y);
}

void menu(mainMenu& main_menu, sf::RenderWindow& window)
{
    menuInit(main_menu, window);
    main_menu.menuStartSprite.setTexture(main_menu.menuStartTexture);
    main_menu.musicMenuBack.play();
    bool isMenu = 1;
    bool checkBoxOneActivated = false;
    bool checkBoxTwoActivated = false;
    bool checkBoxThreeActivated = false;
    bool checkBoxFourActivated = false;

    int menuNum = 0;
    sf::Clock checkBoxTimer;
    checkBoxTimer.restart();
    int checkBoxNum = 0;
    while (isMenu)
    {

        menuNum = 0;
        window.clear();

        if (sf::IntRect(100, 470, 408, 98).contains(sf::Mouse::getPosition(window)))
        {
            main_menu.menuExitSprite.setTexture(main_menu.menuExitTexture);
            main_menu.menuHelpSprite.setTexture(main_menu.menuHelpTexture);
            main_menu.menuStartSprite.setTexture(main_menu.menuStartFocusTexture);
            menuNum = 1;
        }
        if (sf::IntRect(100, 565, 408, 98).contains(sf::Mouse::getPosition(window)))
        {
            main_menu.menuExitSprite.setTexture(main_menu.menuExitTexture);
            main_menu.menuStartSprite.setTexture(main_menu.menuStartTexture);
            main_menu.menuHelpSprite.setTexture(main_menu.menuHelpFocusTexture);
            menuNum = 2;
        }
        if (sf::IntRect(100, 659, 408, 98).contains(sf::Mouse::getPosition(window)))
        {
            main_menu.menuStartSprite.setTexture(main_menu.menuStartTexture);
            main_menu.menuHelpSprite.setTexture(main_menu.menuHelpTexture);

            main_menu.menuExitSprite.setTexture(main_menu.menuExitFocusTexture);
            menuNum = 3;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // checkbox one
            if (sf::IntRect(870, 147, 59, 59).contains(sf::Mouse::getPosition(window)) && checkBoxOneActivated == false)
            {
                main_menu.checkBoxOnSprite.setPosition(870, 147);
                main_menu.checkBoxOnSprite.setTexture(main_menu.checkBoxOnTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 1;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxOneActivated = true;
                }
            }
            if (sf::IntRect(870, 147, 59, 59).contains(sf::Mouse::getPosition(window)) && checkBoxOneActivated == true)
            {
                main_menu.checkBoxOnSprite.setPosition(870, 147);
                main_menu.checkBoxOnSprite.setTexture(main_menu.checkBoxTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 0;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxOneActivated = false;
                }
            }
            // checkbox two
            if (sf::IntRect(870, 254, 59, 59).contains(sf::Mouse::getPosition(window)) && checkBoxTwoActivated == false)
            {
                main_menu.checkBoxOnSprite.setPosition(870, 254);
                main_menu.checkBoxOnSprite.setTexture(main_menu.checkBoxOnTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 2;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxTwoActivated = true;
                }
            }

            if (sf::IntRect(870, 254, 59, 59).contains(sf::Mouse::getPosition(window)) && checkBoxTwoActivated == true)
            {
                main_menu.checkBoxOnSprite.setPosition(870, 254);
                main_menu.checkBoxOnSprite.setTexture(main_menu.checkBoxTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 2;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxTwoActivated = false;
                }
            }
            // checkBox three
            if (sf::IntRect(870, 500, 59, 59).contains(sf::Mouse::getPosition(window)) &&
                checkBoxThreeActivated == false)
            {
                main_menu.checkBoxOnSpriteTwo.setPosition(870, 500);
                main_menu.checkBoxOnSpriteTwo.setTexture(main_menu.checkBoxOnTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 3;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxThreeActivated = true;
                }
            }

            if (sf::IntRect(870, 500, 59, 59).contains(sf::Mouse::getPosition(window)) &&
                checkBoxThreeActivated == true)
            {
                main_menu.checkBoxOnSpriteTwo.setPosition(870, 500);
                main_menu.checkBoxOnSpriteTwo.setTexture(main_menu.checkBoxTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 3;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxThreeActivated = false;
                }
            }

            // four checkbox
            if (sf::IntRect(870, 653, 59, 59).contains(sf::Mouse::getPosition(window)) &&
                checkBoxFourActivated == false)
            {

                main_menu.checkBoxOnSpriteTwo.setPosition(870, 653);
                main_menu.checkBoxOnSpriteTwo.setTexture(main_menu.checkBoxOnTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 3;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxFourActivated = true;
                }
            }

            if (sf::IntRect(870, 653, 59, 59).contains(sf::Mouse::getPosition(window)) && checkBoxFourActivated == true)
            {

                main_menu.checkBoxOnSpriteTwo.setPosition(870, 653);
                main_menu.checkBoxOnSpriteTwo.setTexture(main_menu.checkBoxTexture);
                if (checkBoxTimer.getElapsedTime().asSeconds() >= 0.2f)
                {

                    checkBoxTimer.restart();
                    checkBoxNum = 3;
                    std::cout << "checkBoxNum = " << checkBoxNum << std::endl;
                    checkBoxFourActivated = false;
                }
            }

            if (menuNum == 1)
            {
                isMenu = false; // если нажали первую кнопку, то выходим из меню
            }
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
        window.draw(main_menu.checkBoxOnSprite);
        window.draw(main_menu.checkBoxOnSpriteTwo);
        window.display();
    }
}
} // namespace ApplesGame
#endif // APPLEGAME_MAINMENU_H
