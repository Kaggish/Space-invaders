#pragma once
#include "batch.hpp"

namespace runner
{
	class Bullet
	{
	private:
		sf::Vector2f m_bulletSize = { 4.0f, 4.0f };
		sf::Vector2f m_bulletPosition;

		float m_speed;
		int m_bulletLifeTime;

		bool m_isAlive = true;
		bool m_isPlayerBullet;

		sf::FloatRect m_box;

	private:
		void Movement();
		void SetBox();

	public:
		Bullet(float p_entityX, float p_entityY, float p_speed, bool p_isPlayerBullet);
		~Bullet() = default;
		void Update();
		void Draw(PrimitiveBatch& p_batch);

		int GetLifeTime();
		bool GetPlayerBullet();
		bool GetIsAlive();
		sf::FloatRect GetBox();
		
		void SetAlive(bool p_isALive);
	};
}