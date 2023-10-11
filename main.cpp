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
  Enemy * froakieRight = new Enemy(1, sf::Vector2f(0,0.1), froakieSprite, sf::Vector2f(400,0));
  int * numWaves = new int;
  *numWaves = 10;

  Wave ** waves = new Wave*[10];
  for (int i =0; i < 10; i++){
    waves[i] = new Wave;
  }
  waves[0]->addEnemy(froakieLeft);
  waves[0]->addEnemy(froakieRight);
  waves[0]->setEnemyTime(1);
  MainGame game(sf::Vector2f(480,640), "Game", waves, numWaves);
  sf::Time time;
  game.run();


}
