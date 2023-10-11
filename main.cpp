#include <SFML/Graphics.hpp>
//For Debugging
#include <iostream>
#include "MainGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"
int main() {
  //Defining First Enemy (Froakie)
  sf::Texture* froakieSprite = new sf::Texture;
  froakieSprite->loadFromFile("enemy.png");
  Enemy * froakieLeft = new Enemy(1, sf::Vector2f(0,0.1), froakieSprite, sf::Vector2f(0,0));
  Enemy * froakieRight = new Enemy(1, sf::Vector2f(0,0.1), froakieSprite, sf::Vector2f(480,0));
  int * numWaves = new int;
  *numWaves = 1;
  Wave * waves[1];
  waves[0] = new Wave(froakieLeft, 3, 1);
  MainGame game(sf::Vector2f(480,640), "Game", waves, numWaves);
  sf::Time time;
  game.run();


}
