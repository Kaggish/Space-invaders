#pragma once
#include "batch.hpp"

namespace runner
{
	class Enemy
	{
	private:
		sf::Vector2f m_enemyPosition;

		bool m_isAlive = true;
		bool m_MovingRight = false;
		bool m_MovingDown = false;

		int m_animationCounter = 0;
		int m_shootingTimer = rand() % 300 + 1;

		sf::Sprite m_enemySprite_Moving1;
		sf::Sprite m_enemySprite_Moving2;

		sf::FloatRect m_box;


	private:
		void SetBox();
		void Movement();

	public:
		Enemy(float p_enemyX, float p_enemyY);
		~Enemy() = default;
		void SetTexture(const sf::Texture& p_texture);
		void Update();
		void Draw(sf::RenderWindow& p_screen);

		float GetX();
		float GetY();
		float GetSpriteSize();
		int GetShootingTime();
		bool GetMovingDown();
		bool GetAlive();
		sf::FloatRect GetBox();

		void SetMovingRight(bool p_movingRight);
		void SetMovingDown(bool p_movingDown);
		void SetX(float p_xPos);
		void SetY(float p_yPos);
		void SetAlive(bool p_isAlive);
		void SetShootingTimer(int p_shootingTimer);
	};
}