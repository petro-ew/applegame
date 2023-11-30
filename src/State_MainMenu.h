//
// Created by petroew on 24.11.23.
//

#ifndef APPLEGAME_STATE_MAINMENU_H
#define APPLEGAME_STATE_MAINMENU_H

#include "BaseState.h"
#include "EventManager.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

class State_MainMenu : public BaseState
{
public:
    State_MainMenu(StateManager* l_stateManager);
    ~State_MainMenu();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void MouseClick(EventDetails* l_details);
    void MousePoint(EventDetails* l_details);

private:
    sf::Font m_font;
    sf::Text m_text;

    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    sf::Vector2f m_checkboxSize;
    sf::Vector2f m_checkboxPos;
    unsigned int m_buttonPadding;
    unsigned int m_checkboxPadding;

    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];
    sf::RectangleShape m_rect_checkbox[4];
    sf::Text m_labels_checkbox[4];
    sf::Texture m_texture_on_checkbox;
    sf::Sprite m_sprite_on_checkbox;
    sf::Texture m_logo_texture;
    sf::Sprite m_logo_sprite;
    sf::Music musicMenuBack;
};

#endif // APPLEGAME_STATE_MAINMENU_H
