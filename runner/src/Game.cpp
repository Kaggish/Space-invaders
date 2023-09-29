#include "Game.h"

void runner::Game::LoadAssets() 
{
	m_playerTexture.loadFromFile("assets/Player_Texture.png");
	m_enemyTexture.loadFromFile("assets/Enemy_Texture.png");
	m_font.loadFromFile("assets/Freshman.ttf");
}

void runner::Game::SetAssets()
{
	m_player.SetTextures(m_playerTexture);
	m_player.SetFont(m_font);
	m_UI.SetFont(m_font);
	m_UI.MenuText();
	m_score.SetFont(m_font);
}

void runner::Game::CreateStars()
{
	if (m_star.size() < m_starLayer1amount)
	{
		for (int i = 0; i < m_starLayer1amount; i++)
		{
			m_star.push_back(Background(static_cast <float> (rand() % m_screenWidth + 1), static_cast <float> (rand() % m_screenHeight + 1), 3));
		}
		for (int i = 0; i < m_starLayer2amount; i++)
		{
			m_star.push_back(Background(static_cast <float> (rand() % m_screenWidth + 1), static_cast <float> (rand() % m_screenHeight + 1), 9));
		}
	}
}

void runner::Game::CreateEnemies()
{
	if (m_enemy.size() < m_maxAmmountOfEnemies && m_enemy.size() <= 0)
	{
		for (m_ammountOfEnemies = 0; m_ammountOfEnemies < m_maxAmmountOfEnemies; m_ammountOfEnemies++)
		{
			m_enemy.push_back(Enemy(75.0f, 50.0f));
		}
		SetEnemyPosition();
	}
	for (auto i = 0; i < m_enemy.size(); i++)
	{
		m_enemy.at(i).SetTexture(m_enemyTexture);
	}
}

void runner::Game::SetEnemyPosition()
{
	for (int i = 1; i < 10; i++)
	{
		m_enemy.at(i).SetX(m_enemy.at(i - 1).GetX() + m_enemy.at(i).GetSpriteSize() + 5);
	}

	for (int i = 11; i < 21; i++)
	{
		m_enemy.at(10).SetX(m_enemy.at(0).GetX()); 
		m_enemy.at(10).SetY(m_enemy.at(0).GetY() + m_enemy.at(i).GetSpriteSize());
		m_enemy.at(i).SetX(m_enemy.at(i - 1).GetX() + m_enemy.at(i).GetSpriteSize() + 5);
		m_enemy.at(i).SetY(m_enemy.at(10).GetY());
	}

	for (int i = 21; i < m_enemy.size(); i++)
	{
		m_enemy.at(20).SetX(m_enemy.at(0).GetX());
		m_enemy.at(20).SetY(m_enemy.at(11).GetY() + m_enemy.at(i).GetSpriteSize());
		m_enemy.at(i).SetX(m_enemy.at(i - 1).GetX() + m_enemy.at(i).GetSpriteSize() + 5);
		m_enemy.at(i).SetY(m_enemy.at(20).GetY());
	}
}

void runner::Game::DeleteEnemies()
{
	for (int i = 0; i < m_enemy.size(); i++)
	{
		if (m_enemy.at(i).GetAlive() == false)
		{
			if (i < m_enemy.size() - 1)
			{
				std::swap(m_enemy.at(i), m_enemy.at(i + 1));
			}
			if (i == m_enemy.size() - 1)
			{
				m_enemy.pop_back();
			}
		}
	}
}

void runner::Game::AddBullet()
{
	for (int i = 0; i < m_enemy.size(); i++)
	{
		if (m_enemy.at(i).GetShootingTime() == 0)
		{
			m_bullet.push_back(Bullet(m_enemy.at(i).GetX(), m_enemy.at(i).GetY(), 10.0f, false));
			m_enemy.at(i).SetShootingTimer(rand() % 300 + 1);
		}
	}

	if (m_player.GetShooting() == true && m_player.GetShootingTime() <= 0)
	{
		m_bullet.push_back(Bullet(m_player.GetX(), m_player.GetY(), -10.0f, true));
		m_player.SetShootingTime(120);
	}
}

void runner::Game::DeleteBullet()
{
	for (int i = 0; i < m_bullet.size(); i++)
	{
		if (m_bullet.at(i).GetLifeTime() == 0 || m_bullet.at(i).GetIsAlive() == false)
		{
			if (i < m_bullet.size() - 1)
			{
				std::swap(m_bullet.at(i), m_bullet.at(i + 1));
			}
			if (i == m_bullet.size() - 1)
			{
				m_bullet.pop_back();
			}
		}
	}
}

bool runner::Game::BoxVsBox(sf::FloatRect p_entityLeft, sf::FloatRect p_entityRight)
{
	if (p_entityLeft.left + p_entityLeft.width >= p_entityRight.left && p_entityRight.left + p_entityRight.width >= p_entityLeft.left
		&& p_entityLeft.top + p_entityLeft.height >= p_entityRight.top && p_entityRight.top + p_entityRight.height >= p_entityLeft.top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void runner::Game::DoCollision()
{
	/*Enemy bullet vs player*/
	for (int i = 0; i < m_enemy.size(); i++)
	{
		for (int k = 0; k < m_bullet.size(); k++)
		{
			if (BoxVsBox(m_bullet.at(k).GetBox(), m_player.GetBox()) && m_bullet.at(k).GetPlayerBullet() == false)
			{
				m_bullet.at(k).SetAlive(false);
				m_player.SetHealthPoints(m_player.GetHealthPoints() - 1);
				if (m_player.GetHealthPoints() == 0)
				{
					m_enemy.clear();
					m_bullet.clear();
					m_runningState = false;
					m_gameOverState = true;
				}
				return;
			}
		}
	}
	//Player bullet vs enemy
	for (int i = 0; i < m_enemy.size(); i++)
	{
		for (int k = 0; k < m_bullet.size(); k++)
		{
			if (BoxVsBox(m_enemy.at(i).GetBox(), m_bullet.at(k).GetBox()) && m_bullet.at(k).GetPlayerBullet() == true)
			{
				m_bullet.at(k).SetAlive(false);
				m_enemy.at(i).SetAlive(false);
				m_score.AddScore();
			}
		}
	}
	//Enemy vs player
	for (int i = 0; i < m_enemy.size(); i++)
	{
		if (BoxVsBox(m_enemy.at(i).GetBox(), m_player.GetBox()))
		{
			m_enemy.clear();
			m_bullet.clear();
			m_runningState = false;
			m_gameOverState = true;
		}
	}
	//Enemy vs screenbounds
	for (int i = 0; i < m_enemy.size(); i++)
	{
		if (m_enemy.at(i).GetX() + m_enemy.at(i).GetSpriteSize() >= m_screenWidth)
		{
			for (int k = 0; k < m_enemy.size(); k++)
			{
				m_enemy.at(k).SetMovingRight(false);
				m_enemy.at(k).SetMovingDown(true);
			}
			return;
		}
		else if (m_enemy.at(i).GetX() - m_enemy.at(i).GetSpriteSize() <= 0.0f)
		{
			for (int k = 0; k < m_enemy.size(); k++)
			{
				m_enemy.at(k).SetMovingRight(true);
				m_enemy.at(k).SetMovingDown(true);
			}
			return;
		}

		if (m_enemy.at(i).GetX() > 0.0f && m_enemy.at(i).GetX() + m_enemy.at(i).GetSpriteSize() < m_screenWidth)
		{
			for (int k = 0; k < m_enemy.size(); k++)
			{
				m_enemy.at(k).SetMovingDown(false);
			}
		}
	}
}

void runner::Game::Input()
{
	m_player.Input();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_menuState == true)
	{
		m_menuState = false;
		m_runningState = true;
		m_player.SetHealthPoints(3);
		m_score.SetScore(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && m_gameOverState == true)
	{
		m_gameOverState = false;
		m_menuState = true;
	}
}

void runner::Game::Update() 
{
	CreateStars();
	for (auto i = 0; i < m_star.size(); i++)
	{
		m_star.at(i).Update();
	}

	if (m_player.GetHealthPoints() > 0 && m_runningState == true)
	{
		CreateEnemies();
		DeleteEnemies();
		AddBullet();
		DeleteBullet();
		m_player.Update();
		m_score.ScoreText();

		for (int i = 0; i < m_enemy.size(); i++)
		{
			m_enemy.at(i).Update();
		}

		for (int i = 0; i < m_bullet.size(); i++)
		{
			m_bullet.at(i).Update();
		}
		DoCollision();
	}

	if (m_gameOverState == true)
	{
		m_score.GameOverText();
		m_score.SetHighScore();
	}
}

void runner::Game::Draw(sf::RenderWindow& p_screen, PrimitiveBatch& p_batch) 
{
	for (int i = 0; i < m_star.size(); i++)
	{
		m_star.at(i).Draw(p_batch);
	}

	if (m_menuState == true)
	{
		m_UI.Draw(p_screen);
	}

	if (m_player.GetHealthPoints() > 0 && m_runningState == true)
	{
		m_player.Draw(p_screen);
		m_score.DrawScore(p_screen);
		for (int i = 0; i < m_enemy.size(); i++)
		{
			m_enemy.at(i).Draw(p_screen);
		}
		for (int i = 0; i < m_bullet.size(); i++)
		{
			m_bullet.at(i).Draw(p_batch);
		}
	}

	if (m_gameOverState == true)
	{
		m_score.Draw(p_screen);
		m_score.DrawScore(p_screen);
	}
}
