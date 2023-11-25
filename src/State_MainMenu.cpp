//
// Created by petroew on 24.11.23.
//

#include "State_MainMenu.h"
#include "StateManager.h"
#include <cassert>

State_MainMenu::State_MainMenu(StateManager* l_stateManager) : BaseState(l_stateManager)
{
}

State_MainMenu::~State_MainMenu()
{
}

void State_MainMenu::OnCreate()
{
    m_font.loadFromFile("Resources/Fonts/arial.ttf");
    m_text.setFont(m_font);
    m_text.setString(sf::String("Apple Games"));
    m_text.setFillColor(sf::Color(0, 232, 52));
    m_text.setCharacterSize(32);
    m_text.setStyle(sf::Text::Bold);

    sf::FloatRect textRect = m_text.getLocalBounds();
    // m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    m_text.setPosition(150, 100);

    m_buttonSize = sf::Vector2f(300.0f, 32.0f);
    m_buttonPos = sf::Vector2f(250, 200);
    m_buttonPadding = 10; // 4px.

    m_checkboxSize = sf::Vector2f(110.0f, 110.0f);
    m_checkboxPos = sf::Vector2f(400, 200);
    m_checkboxPadding = 10;

    assert(m_texture_on_checkbox.loadFromFile("Resources/Menu/on.png"));
    m_sprite_on_checkbox.setTexture(m_texture_on_checkbox);
    assert(musicMenuBack.openFromFile("Resources/Menu/menu1.wav"));

    musicMenuBack.setLoop(true);
    musicMenuBack.setVolume(50);
    musicMenuBack.play();

    std::string str[3];
    str[0] = "PLAY";
    str[1] = "CREDITS";
    str[2] = "EXIT";

    for (int i = 0; i < 3; ++i)
    {
        sf::Vector2f buttonPosition(m_buttonPos.x, m_buttonPos.y + (i * (m_buttonSize.y + m_buttonPadding)));
        m_rects[i].setSize(m_buttonSize);
        m_rects[i].setFillColor(sf::Color(0, 0, 0));
        m_rects[i].setOutlineThickness(2.f);
        m_rects[i].setOutlineColor(sf::Color(0, 232, 52));
        m_rects[i].setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
        m_rects[i].setPosition(buttonPosition);

        m_labels[i].setFont(m_font);
        m_labels[i].setString(sf::String(str[i]));
        m_labels[i].setStyle(sf::Text::Bold);
        m_labels[i].setCharacterSize(24);
        m_labels[i].setFillColor(sf::Color(0, 232, 52));
        sf::FloatRect rect = m_labels[i].getLocalBounds();
        m_labels[i].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

        m_labels[i].setPosition(buttonPosition);
    }

    for (int i = 0; i < 4; i++)
    {
    }

    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::MainMenu, "Mouse_Left", &State_MainMenu::MouseClick, this);
}

void State_MainMenu::OnDestroy()
{
    musicMenuBack.stop();
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::MainMenu, "Mouse_Left");
}

void State_MainMenu::Activate()
{

    if (m_stateMgr->HasState(StateType::Game) && m_labels[0].getString() == "PLAY")
    {
        musicMenuBack.play();
        m_labels[0].setString(sf::String("RESUME"));
        sf::FloatRect rect = m_labels[0].getLocalBounds();
        m_labels[0].setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    }
}

void State_MainMenu::MouseClick(EventDetails* l_details)
{
    sf::Vector2i mousePos = l_details->m_mouse;

    float halfX = m_buttonSize.x / 2.0f;
    float halfY = m_buttonSize.y / 2.0f;
    for (int i = 0; i < 3; ++i)
    {
        if (mousePos.x >= m_rects[i].getPosition().x - halfX && mousePos.x <= m_rects[i].getPosition().x + halfX &&
            mousePos.y >= m_rects[i].getPosition().y - halfY && mousePos.y <= m_rects[i].getPosition().y + halfY)
        {
            if (i == 0)
            {
                musicMenuBack.stop();
                m_stateMgr->SwitchTo(StateType::Game);
            }
            else if (i == 1)
            {
                // Credits state.
            }
            else if (i == 2)
            {
                m_stateMgr->GetContext()->m_wind->Close();
            }
        }
    }
}

void State_MainMenu::Draw()
{
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_text);
    for (int i = 0; i < 3; ++i)
    {
        window->draw(m_rects[i]);
        window->draw(m_labels[i]);
    }
}

void State_MainMenu::Update(const sf::Time& l_time)
{
}
void State_MainMenu::Deactivate()
{
}