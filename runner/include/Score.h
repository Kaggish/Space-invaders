#pragma once
#include "batch.hpp"

namespace runner
{
	class Score
	{
	private:
		int m_score = 0;
		int m_currentHighScore = 0;

		sf::Font m_font;
		sf::Text m_scoreText;
		sf::Text m_highScoreText;
		sf::Text m_gameOverText;

	public:
		void GameOverText();
		void ScoreText();
		void AddScore();
		void SetHighScore();
		void Draw(sf::RenderWindow& p_screen);
		void DrawScore(sf::RenderWindow& p_screen);

		void SetFont(const sf::Font& p_font);
		void SetScore(int p_score);
	};
}