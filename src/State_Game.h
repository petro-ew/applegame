//
// Created by petroew on 24.11.23.
//

#ifndef APPLEGAME_STATE_GAME_H
#define APPLEGAME_STATE_GAME_H

#pragma once
#include "BaseState.h"
#include "EventManager.h"

class State_Game : public BaseState
{
public:
    State_Game(StateManager* l_stateManager);
    ~State_Game();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void MainMenu(EventDetails* l_details);
    void Pause(EventDetails* l_details);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_increment;
};

#endif // APPLEGAME_STATE_GAME_H
