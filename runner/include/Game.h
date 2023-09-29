#pragma once
#include "batch.hpp"
#include "Player.h"
#include "Enemies.h"
#include "Background.h"
#include "UI.h"
#include "Score.h"
#include "Bullets.h"

namespace runner
{
	class Game
	{
	private:
		Player m_player;
		UI m_UI;
		Score m_score;
		std::vector<Enemy> m_enemy;
		std::vector<Background> m_star;
		std::vector<Bullet> m_bullet;

		sf::Texture m_playerTexture;
		sf::Texture m_enemyTexture;

		sf::Font m_font;

		int m_ammountOfEnemies = 0;
		const int m_maxAmmountOfEnemies = 30;

		const int m_starLayer1amount = 30;
		const int m_starLayer2amount = 25;

		const int m_screenWidth = 700;
		const int m_screenHeight = 950;

		bool m_menuState = true, m_runningState = false, m_gameOverState = false;

	private:
		void CreateEnemies();
		void SetEnemyPosition();
		void DeleteEnemies();

		void CreateStars();

		void AddBullet();
		void DeleteBullet();

		void DoCollision();
		bool BoxVsBox(sf::FloatRect p_entityLeft, sf::FloatRect p_entityRight);

	public:
		void LoadAssets();
		void SetAssets();
		void Input();
		void Update();
		void Draw(sf::RenderWindow& p_screen, PrimitiveBatch& p_batch);
	};
}