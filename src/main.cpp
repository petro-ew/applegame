// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)
// gcc -c -std=c++20 -fmodules-ts  *.cpp
// g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include "Constants.h"
#include "Game.h"
// #include <string>
// #include "MainMenu.h"

// int main()
void main(int argc, void** argv[])
{
    // Program entry point.
    Game game;
    while (!game.GetWindow()->IsDone())
    {
        game.Update();
        game.Render();
        game.LateUpdate();
    }
    // return 0;
}

/*
int main()
{
    using namespace ApplesGame;
    int seed = (int)time(nullptr);
    srand(seed);
    // Init window
    mainMenu main_menu;

    sf::RenderWindow windowMenu(sf::VideoMode(1920, 1080), "Apples game!");
    menuInit(main_menu, windowMenu);
    menu(main_menu, windowMenu);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

    //   Game initialization
    Game game;
    initGame(game);
    // Init game clocks
    sf::Clock gameClock;
    float lastTime = gameClock.getElapsedTime().asSeconds();
    // Main loop
    while (window.isOpen())
    {
        // Reduce framerate to not spam CPU and GPU
        sf::sleep(sf::microseconds(16));
        // Calculate time delta
        float currentTime = gameClock.getElapsedTime().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        // Read events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                break;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H)
            {
                initHelpDeskText(game.ui, true);
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::H)
            {
                initHelpDeskText(game.ui, false);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
            {
                setSoundEnable(game.isSoundEnable, game);
            }
        }
        updateGame(game, deltaTime);
        // Draw game
        window.clear();
        drawGame(game, window);
        window.display();
    }


    // Deinitialization
    deinializeGame(game);
    return 0;
}

*/
