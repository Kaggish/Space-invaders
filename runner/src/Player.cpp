#include "Player.h"

void runner::Player::SetTextures(const sf::Texture& p_texture)
{
	m_playerSprite_Idle.setTexture(p_texture);
	m_playerSprite_Idle.setTextureRect(sf::IntRect(0, 0, m_spriteSizeI, m_spriteSizeI));
	m_playerSprite_Idle.setOrigin((m_spriteSizeF / 2), (m_spriteSizeF / 2));

	m_playerSprite_Moving1.setTexture(p_texture);
	m_playerSprite_Moving1.setTextureRect(sf::IntRect(m_spriteSizeI, 0, m_spriteSizeI, m_spriteSizeI));
	m_playerSprite_Moving1.setOrigin((m_spriteSizeF / 2), (m_spriteSizeF / 2));

	m_playerSprite_Moving2.setTexture(p_texture);
	m_playerSprite_Moving2.setTextureRect(sf::IntRect((m_textureSizeI - m_spriteSizeI), 0, m_spriteSizeI, m_spriteSizeI));
	m_playerSprite_Moving2.setOrigin((m_spriteSizeF / 2), (m_spriteSizeF / 2));
}

void runner::Player::SetFont(const sf::Font& p_font)
{
	m_font = p_font;
}

void runner::Player::HealthPointsText()
{
	m_healthUI.setFont(m_font);
	m_healthUI.setString("Lives: " + std::to_string(m_healthPoints));
	m_healthUI.setCharacterSize(24);
	m_healthUI.setPosition(0, 30);
}

void runner::Player::SetBox()
{
	m_box.left = m_playerPosition.x - (m_spriteSizeF / 2);
	m_box.top = m_playerPosition.y - (m_spriteSizeF / 2);
	m_box.height = m_spriteSizeF;
	m_box.width = m_spriteSizeF;
}

void runner::Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_IsMoving == true)
	{
		m_playerPosition.x = m_playerPosition.x + m_moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_IsMoving == true)
	{
		m_playerPosition.x = m_playerPosition.x - m_moveSpeed;
	}

}

void runner::Player::Wrapping()
{
	if (m_playerPosition.x - m_spriteSizeF > 700)
	{
		m_playerPosition.x = 0;
	}
	else if (m_playerPosition.x + m_spriteSizeF < 0)
	{
		m_playerPosition.x = 700;
	}
}

void runner::Player::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_IsMoving = true;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_IsMoving = true;
	}
	else
	{
		m_IsMoving = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_shooting = true;
	}
	else
	{
		m_shooting = false;
	}
}

void runner::Player::Update() 
{
	Movement();
	SetBox();
	Wrapping();
	HealthPointsText();
	m_shootingTimer--;
}

void runner::Player::Draw(sf::RenderWindow& p_screen)
{
	p_screen.draw(m_healthUI);
	if (m_IsMoving == false)
	{
		m_playerSprite_Idle.setPosition(m_playerPosition);
		p_screen.draw(m_playerSprite_Idle);
	}
	else if(m_IsMoving == true)
	{
		if (m_animationCounter < 30)
		{
			m_playerSprite_Moving1.setPosition(m_playerPosition);
			p_screen.draw(m_playerSprite_Moving1);
		}
		else if (m_animationCounter > 30 && m_animationCounter < 60)
		{
			m_playerSprite_Moving2.setPosition(m_playerPosition);
			p_screen.draw(m_playerSprite_Moving2);
			m_animationCounter = 0;
		}
	}
}

sf::FloatRect runner::Player::GetBox()
{
	return m_box;
}

float runner::Player::GetX()
{
	return m_playerPosition.x;
}

float runner::Player::GetY()
{
	return m_playerPosition.y;
}

bool runner::Player::GetShooting()
{
	return m_shooting;
}

float runner::Player::GetSpriteSize()
{
	return m_spriteSizeF;
}

int runner::Player::GetShootingTime()
{
	return m_shootingTimer;
}

int runner::Player::GetHealthPoints()
{
	return m_healthPoints;
}

void runner::Player::SetHealthPoints(int p_health)
{
	m_healthPoints = p_health;
}

void runner::Player::SetShootingTime(int p_shootingTimer)
{
	m_shootingTimer = p_shootingTimer;
}
