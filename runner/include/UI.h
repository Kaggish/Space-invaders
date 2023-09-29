#pragma once
#include "batch.hpp"

namespace runner
{
	class UI
	{
	private:
		sf::Font m_font;
		sf::Text m_gameName;
		sf::Text m_startGame;

	public:
		UI() = default;
		~UI() = default;
		void SetFont(const sf::Font& p_font);
		void MenuText();
		void Draw(sf::RenderWindow& p_screen);
	};
}