#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <SFML/Graphics.hpp>
#include <MainMenu.h>
class Instructions {
 private:
  sf::RectangleShape background;
  sf::Texture* backgroundArt;

 public:
  Instructions() {
    backgroundArt = new sf::Texture;
    background.setSize(sf::Vector2f(480, 640));
    backgroundArt->loadFromFile("Instructions.png");
    background.setTexture(backgroundArt);
  }

  void Draw(sf::RenderWindow* window) { window->draw(background); }

  void run(sf::RenderWindow* window, MainMenu * mainmenu) {
    while (window->isOpen()) {
      sf::Event event;

      while (window->pollEvent(event)) {
        switch (event.type) {
          case sf::Event::KeyReleased:
            switch (event.key.code) {
              case sf::Keyboard::Escape:
                mainmenu->draw(window);
                break;
            }
            break;
          case sf::Event::Closed:
            window->close();

            break;
        }
      }
      window->clear();
      window->draw(background);
      window->display();
    }
  }
};

#endif