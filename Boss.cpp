#include "Boss.h"
#include "Enemy.h"

//Default Constructor, Sets the Sprite, Position, and Velocity of the boss
Boss::Boss(){
    texture = new sf::Texture;
    texture->loadFromFile("enemyBoss.png");
    this->sprite.setTexture(*texture);
    sprite.setPosition(240,0);
    this->velocity = sf::Vector2f(0,0.01);
    this->sprite.setOrigin(48,64);
    this->enemyLife = 20;
}
//Updates the boss's position. If the y co-ordinate is greater than 100, it will stop moving downwards
void Boss::update(double timeElapsed,sf::RenderWindow* window){
    sf::Vector2f currentPos = sprite.getPosition();
    //The boss will only move downwards if the y position is less than 100. Meaning it stops when it reaches y=100
    if (this->sprite.getPosition().y < 100){
      this->sprite.setPosition(currentPos.x + timeElapsed * velocity.x, currentPos.y + timeElapsed*velocity.y);
    }
    window->draw(sprite);
}
//Shoots and controls the Enemies Bullet Pattern, it will shoot a double - double helix pattern
void Boss::shoot(Entity** objectsToBeDrawn, int* numObjects,
                     int* maxObjects, double totalTime) {
    if (totalTime - timeBulletFired > 0.05) {
      if (*numObjects < *maxObjects) {
        //These four bullets sketch out a circle when a full 3.6 seconds has elapsed, x and y are altered such that four circles are made at once
        objectsToBeDrawn[*numObjects] = new EnemyBullet(sprite.getPosition(), sf::Vector2f(cos(totalTime)*0.1, sin(totalTime)*0.1));
        *numObjects += 1;
        objectsToBeDrawn[*numObjects] = new EnemyBullet(sprite.getPosition(), sf::Vector2f(-cos(totalTime)*0.1, -sin(totalTime)*0.1));
        *numObjects += 1;
        objectsToBeDrawn[*numObjects] = new EnemyBullet(sprite.getPosition(), sf::Vector2f(-cos(totalTime)*0.1, sin(totalTime)*0.1));
        *numObjects += 1;
        objectsToBeDrawn[*numObjects] = new EnemyBullet(sprite.getPosition(), sf::Vector2f(cos(totalTime)*0.1, -sin(totalTime)*0.1));
        *numObjects += 1;
      } else {
        std::cout << "Too many entities!!!" << std::endl;
      }
      timeBulletFired = totalTime;
    }
  }