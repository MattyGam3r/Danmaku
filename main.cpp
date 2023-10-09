#include <SFML/Graphics.hpp>
#include "MainGame.h"
#include "Player.h"
#include "Enemy.h"
int main() {
  MainGame game(sf::Vector2f(480,640), "Game");
  sf::Time time;
  game.run();


}
