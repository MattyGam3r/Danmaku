#include <SFML/Graphics.hpp>
#include "MainGame.h"
#include "Player.h"
int main() {
  MainGame game(sf::Vector2f(480,640), "Game");

  game.run();
}
