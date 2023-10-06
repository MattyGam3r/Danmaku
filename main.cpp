#include <SFML/Graphics.hpp>
#include "MainGame.h"
#include "Player.h"
int main() {
  MainGame game(500, "Game");
  game.run();
}
