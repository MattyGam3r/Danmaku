#include "Bullet.h"
// Default constructor for bullet, sets the tag for itself as 'bullet'
Bullet::Bullet() { setTag("bullet"); }

// Update's the position of the bullet (this is called each frame)
void Bullet::update(double timeElapsed, sf::RenderWindow* window) {
  sf::Vector2f currentPos = sprite.getPosition();
  // std::cout << currentPos.y << " ";
  sprite.setPosition(currentPos.x + timeElapsed * velocity.x,
                     currentPos.y + timeElapsed * velocity.y);
  window->draw(sprite);
}

// This is only for bullets which travel towards points, but still helpful
sf::Vector2f Bullet::getVelocityTowardsPoint(sf::Vector2f startingPoint,
                                             sf::Vector2f endPoint) {
  double xdif = endPoint.x - startingPoint.x;
  double ydif = endPoint.y - startingPoint.y;
  double length = sqrt(pow(xdif, 2) + pow(ydif, 2));
  sf::Vector2f velocityTowardsPoint;
  velocityTowardsPoint.x = xdif / length;
  velocityTowardsPoint.y = ydif / length;
  return velocityTowardsPoint;
}

// This is called when the object collides with the Player
void Bullet::getHit(Entity** objectsToBeDrawn, int* numObjects, int* index) {
  // Moves the array which contains all entities to remove this bullet
  shiftArray(objectsToBeDrawn, numObjects, index);
  // Frees the memory where the bullet is stored
  delete this;
  
}