#include "Background.h"


runner::Background::Background(float p_entityX, float p_entityY, int p_speed)
{
	m_layerPos = { p_entityX, p_entityY };

	m_speed = p_speed;
}

void runner::Background::Wrapping()
{
	if (m_layerPos.y > 950)
	{
		m_layerPos.y = 0;
	}
}

void runner::Background::Movement()
{
	m_layerPos.y = (m_layerPos.y + m_speed);
}

void runner::Background::Update()
{
	Movement();
	Wrapping();
}

void runner::Background::Draw(PrimitiveBatch& p_batch)
{
	p_batch.draw_circle(m_layerPos, m_radius, m_sections, sf::Color::White);
}