#include "Bullets.h"

runner::Bullet::Bullet(float p_entityX, float p_entityY, float p_speed, bool p_isPlayerBullet)
{
	m_bulletPosition.x = p_entityX;
	m_bulletPosition.y = p_entityY;
	m_speed = p_speed;
	m_bulletLifeTime = 120;
	m_isPlayerBullet = p_isPlayerBullet;
}

void runner::Bullet::SetBox()
{
	m_box.left = m_bulletPosition.x;
	m_box.top = m_bulletPosition.y;
	m_box.height = m_bulletSize.x;
	m_box.width = m_bulletSize.y;
}

void runner::Bullet::Movement()
{
	m_bulletPosition.y = (m_bulletPosition.y + m_speed);
}

void runner::Bullet::Update()
{
	SetBox();
	Movement();
	m_bulletLifeTime--;
}

void runner::Bullet::Draw(PrimitiveBatch& p_batch)
{
	p_batch.draw_rectangle(sf::FloatRect(m_bulletPosition, m_bulletSize), sf::Color::Red);
}

int runner::Bullet::GetLifeTime()
{
	return m_bulletLifeTime;
}

bool runner::Bullet::GetIsAlive()
{
	return m_isAlive;
}

sf::FloatRect runner::Bullet::GetBox()
{
	return m_box;
}

bool runner::Bullet::GetPlayerBullet()
{
	return m_isPlayerBullet;
}

void runner::Bullet::SetAlive(bool p_isAlive)
{
	m_isAlive = p_isAlive;
}