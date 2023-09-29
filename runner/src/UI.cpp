#include "UI.h"

void runner::UI::SetFont(const sf::Font& p_font)
{
    m_font = p_font;
}

void runner::UI::MenuText()
{
    m_gameName.setFont(m_font);
    m_gameName.setString("Space Invaders V0.1");
    m_gameName.setCharacterSize(24);
    m_gameName.setPosition(220, 180);

    m_startGame.setFont(m_font);
    m_startGame.setString("Press Enter to Start");
    m_startGame.setCharacterSize(24);
    m_startGame.setPosition(210, 400);
}

void runner::UI::Draw(sf::RenderWindow& p_screen)
{
    p_screen.draw(m_gameName);
    p_screen.draw(m_startGame);
}

