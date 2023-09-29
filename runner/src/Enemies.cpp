#include "Enemies.h"

constexpr float m_spriteSizeF = 50.0f;
constexpr float m_textureSizeF = 150.0f;

constexpr int m_spriteSizeI = 50;
constexpr int m_textureSizeI = 150;

constexpr float m_moveSpeed = 1;

runner::Enemy::Enemy(float p_enemyX, float p_enemyY)
{
	m_enemyPosition = { p_enemyX, p_enemyY };
}

void runner::Enemy::SetTexture(const sf::Texture& p_texture)
{
	m_enemySprite_Moving1.setTexture(p_texture);
	m_enemySprite_Moving1.setTextureRect(sf::IntRect(m_spriteSizeI, 0, m_spriteSizeI, m_spriteSizeI));
	m_enemySprite_Moving1.setOrigin(m_spriteSizeF, m_spriteSizeF);

	m_enemySprite_Moving2.setTexture(p_texture);
	m_enemySprite_Moving2.setTextureRect(sf::IntRect((m_textureSizeI - m_spriteSizeI), 0, m_spriteSizeI, m_spriteSizeI));
	m_enemySprite_Moving2.setOrigin(m_spriteSizeF, m_spriteSizeF);
}

void runner::Enemy::SetBox()
{
	m_box.left = m_enemyPosition.x - (m_spriteSizeF / 2);
	m_box.top = m_enemyPosition.y - (m_spriteSizeF / 2);
	m_box.height = m_spriteSizeF;
	m_box.width = m_spriteSizeF;
}

void runner::Enemy::Movement() 
{
	if (m_MovingDown == true)
	{
		SetY(GetY() + m_spriteSizeF);
	}

	if (m_MovingRight == true)
	{
		SetX(GetX() + m_moveSpeed);
	}
	else
	{
		SetX(GetX() - m_moveSpeed);
	}
}

void runner::Enemy::Update() 
{
	if (m_isAlive == true)
	{
		m_animationCounter++;
		m_shootingTimer--;
		SetBox();
		Movement();
	}
}

void runner::Enemy::Draw(sf::RenderWindow& p_screen)
{
	if (m_isAlive == true)
	{
		m_enemySprite_Moving1.setPosition(m_enemyPosition);
		p_screen.draw(m_enemySprite_Moving1);

		if (m_animationCounter > 30 && m_animationCounter < 60)
		{
			m_enemySprite_Moving2.setPosition(m_enemyPosition);
			p_screen.draw(m_enemySprite_Moving2);
			m_animationCounter = 0;
		}
	}
}

float runner::Enemy::GetX()
{
	return m_enemyPosition.x;
}

float runner::Enemy::GetY()
{
	return m_enemyPosition.y;
}

float runner::Enemy::GetSpriteSize()
{
	return m_spriteSizeF;
}

int runner::Enemy::GetShootingTime()
{
	return m_shootingTimer;
}

sf::FloatRect runner::Enemy::GetBox()
{
	return m_box;
}

bool runner::Enemy::GetMovingDown()
{
	return m_MovingDown;
}

bool runner::Enemy::GetAlive()
{
	return m_isAlive;
}

void runner::Enemy::SetX(float p_xPos)
{
	m_enemyPosition.x = p_xPos;
}

void runner::Enemy::SetY(float p_yPos)
{
	m_enemyPosition.y = p_yPos;
}

void runner::Enemy::SetAlive(bool p_isAlive)
{
	m_isAlive = p_isAlive;
}

void runner::Enemy::SetMovingRight(bool p_movingRight)
{
	m_MovingRight = p_movingRight;
}

void runner::Enemy::SetMovingDown(bool p_movingDown)
{
	m_MovingDown = p_movingDown;
}

void runner::Enemy::SetShootingTimer(int p_shootingTimer)
{
	m_shootingTimer = p_shootingTimer;
}
