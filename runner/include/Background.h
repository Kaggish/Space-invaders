#pragma once
#include "batch.hpp"

namespace runner
{
	class Background
	{
	private:
		sf::Vector2f m_layerPos;

		int m_speed;

		float m_radius = 1.0f;
		int m_sections = 12;

	private:
		void Movement();
		void Wrapping();

	public:
		Background(float p_entityX, float p_entityY, int p_speed);
		~Background() = default;
		void Update();
		void Draw(PrimitiveBatch& p_batch);
	};
}