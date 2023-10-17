//BULLET CLASS
//This is a parent class (and abstract), which provides a base for all bullets
//It contains a getHit function, which tells the bullets what to do when they are hit
//Also contains a 'speed' variable, which is used to determine how fast the bullets travel

#ifndef BULLET_H
#define BULLET_H
#include <iostream>

#include "Entity.h"
#include "cmath"
class Bullet : public Entity {
 protected:
 //This is used to multiply velocities by speeds
  double speed;

 public:
  // Default constructor for bullet, sets the tag for itself as 'bullet'
  Bullet();
  // Update's the position of the bullet (this is called each frame)
  void update(double timeElapsed, sf::RenderWindow* window);
  // This is only for bullets which travel towards points, but still helpful
  sf::Vector2f getVelocityTowardsPoint(sf::Vector2f startingPoint,
                                       sf::Vector2f endPoint);
  // This is called when the object collides with the Player
  void getHit(Entity** objectsToBeDrawn, int* numObjects, int* index);
};

#endif