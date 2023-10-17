//BOSS CLASS
//Is used to define the boss, which is an enemy which contains an advanced bullet pattern
//Has the same features as any other enemy, just with more health and a harder bullet pattern

#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include <cmath>
class Boss : public Enemy {
    private:
    float timeBulletFired = 0;
    sf::Texture * texture;
 public:

  //Default Constructor, Sets the Sprite, Position, and Velocity of the boss
  Boss();
  //Updates the boss's position. If the y co-ordinate is greater than 100, it will stop moving downwards
  void update(double timeElapsed,sf::RenderWindow* window);

  //Shoots and controls the Enemies Bullet Pattern, it will shoot a double - double helix pattern
  void shoot(Entity** objectsToBeDrawn, int* numObjects,
                     int* maxObjects, double totalTime);
};

#endif