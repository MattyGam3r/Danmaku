#ifndef MAINGAME_H
#define MAINGAME_H
#include <SFML/Graphics.hpp>
#include <string>

#include "Player.h"
class MainGame {
 private:
  sf::RenderWindow* window;
  Player* reimu;
  sf::View* view;
 public:
  MainGame(sf::Vector2f size, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title);
    reimu = new Player();
    window->setFramerateLimit(60);
  }

  
  void run() {
    sf::Clock clock;
    while (window->isOpen()) {
      sf::Event e;
      sf::Time timeElapsed = clock.restart();
      while (window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
          window->close();
          delete reimu;
          delete window;
          return;
        }
        if (e.type == sf::Event::KeyPressed){
          if (e.key.code == sf::Keyboard::Escape){
            window->close();
          }
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        reimu->move_right(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        reimu->move_left(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        reimu->move_up(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        reimu->move_down(timeElapsed.asMilliseconds());
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        reimu->setSpeed(0.1);
      }else{
        reimu->setSpeed(0.3);
      }
      window->clear();
      reimu->draw(window);
      window->display();
    }
  }
};

#endif