// application.cpp

#include "application.hpp"

namespace runner
{
   void Application::run()
   {
      const sf::VideoMode mode{ 700, 950 };
      const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
      m_window.create(mode, "pineapple", flags);
      m_window.setFramerateLimit(60);
      if (!m_window.isOpen() || !enter()) {
         return;
      }
      m_window.setKeyRepeatEnabled(false);
      while (m_window.isOpen()) {
         sf::Event event;
         while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::MouseMoved) {
               on_mouse_move({ float(event.mouseMove.x), float(event.mouseMove.y) });
            }
            else if (event.type == sf::Event::KeyPressed) {
               on_key_pressed(event.key.code);
            }
            else if (event.type == sf::Event::Closed) {
               m_window.close();
            }
         }
         m_game.Input();
         if (!update()) {
            m_window.close();
         }

         render();
      }

      exit();
   }

   bool Application::enter()
   {
      m_game.LoadAssets();
      m_game.SetAssets();
      return true;
   }

   void Application::exit()
   {
   }

   bool Application::update()
   {
      m_deltatime = m_clock.restart();
      m_game.Update();
      return m_running;
   }

   void Application::render()
   {  
      m_batch.clear();
      m_window.clear(sf::Color::Black);
      m_game.Draw(m_window, m_batch);
      m_batch.present(m_window);
      m_window.display();
   }

   void Application::on_mouse_move(const sf::Vector2f &position) 
   {
      m_mouse_position = position;
   }

   void Application::on_key_pressed(const sf::Keyboard::Key key)
   {
      if (key == sf::Keyboard::Key::Escape) {
         m_running = false;
      }
   }
} // !runner
