#pragma once
#include "batch.hpp"

namespace runner
{
	class Player
	{
	private:

		sf::Vector2f m_playerPosition = { 350.0f, 850.0f };
									    
		int m_healthPoints = 3;
		int m_animationCounter = 0;
		int m_shootingTimer = 0;
		const int m_spriteSizeI = 50;
		const int m_textureSizeI = 150;

		const float m_spriteSizeF = 50.0f;
		const float m_textureSizeF = 150.0f;
		const float m_moveSpeed = 5;


		bool m_IsAlive = true;
		bool m_IsMoving = false;
		bool m_shooting = false;

		sf::Texture m_playerTexture;
		sf::Sprite m_playerSprite_Idle;
		sf::Sprite m_playerSprite_Moving1;
		sf::Sprite m_playerSprite_Moving2;

		sf::FloatRect m_box;

		sf::Text m_healthUI;
		sf::Font m_font;

	private:
		void SetBox();
		void Movement();
		void Wrapping();

	public:
		Player() = default;
		~Player() = default;
		void HealthPointsText();
		void Input();
		void Update();
		void Draw(sf::RenderWindow& p_screen);

		int GetHealthPoints();
		bool GetShooting();
		int GetShootingTime();
		float GetX();
		float GetY();
		float GetSpriteSize();
		sf::FloatRect GetBox();

		void SetHealthPoints(int p_health);
		void SetShootingTime(int p_shootingTimer);
		void SetTextures(const sf::Texture& p_texture);
		void SetFont(const sf::Font& p_font);
	};
}