#include "Score.h"


void runner::Score::SetFont(const sf::Font& p_font)
{
	m_font = p_font;
}

void runner::Score::GameOverText()
{
	m_gameOverText.setFont(m_font);
	m_gameOverText.setString("GameOver!");
	m_gameOverText.setCharacterSize(24);
	m_gameOverText.setPosition(270, 200);

	m_highScoreText.setFont(m_font);
	m_highScoreText.setString("HighScore: " + std::to_string(m_currentHighScore));
	m_highScoreText.setCharacterSize(24);
	m_highScoreText.setPosition(260, 300);
}

void runner::Score::ScoreText()
{
	m_scoreText.setFont(m_font);
	m_scoreText.setString("Score: " + std::to_string(m_score));
	m_scoreText.setCharacterSize(24);
	m_scoreText.setPosition(0, 0);
}

void runner::Score::AddScore()
{
	m_score++;
}


void runner::Score::Draw(sf::RenderWindow& p_screen)
{
	p_screen.draw(m_gameOverText);
	p_screen.draw(m_highScoreText);
}

void runner::Score::DrawScore(sf::RenderWindow& p_screen)
{
	p_screen.draw(m_scoreText);
}

void runner::Score::SetHighScore()
{
	if (m_score > m_currentHighScore)
	{
		m_currentHighScore = m_score;
	}
}

void runner::Score::SetScore(int p_score)
{
	m_score = p_score;
}