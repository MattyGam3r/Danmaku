#ifndef MAINGAME_H
#define MAINGAME_H
#include <SFML/Graphics.hpp>
#include <string>

#include "Player.h"
class MainGame {
 private:
  sf::RenderWindow* window;
  Player* reimu;

 public:
  MainGame(int size, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(size, size), title);
    reimu = new Player();
    window->setFramerateLimit(60);
  }
  void run() {
    while (window->isOpen()) {
      sf::Event e;
      while (window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
          window->close();
          delete reimu;
          delete window;
          return;
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        reimu->move_right(4.5);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        reimu->move_left(4.5);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        reimu->move_up(4.5);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        reimu->move_down(4.5);
      }
      window->clear();
      reimu->draw(window);
      window->display();
    }
  }
};

#endif