#include "Enemy.h"
// Constructor which provides the depth of the enemy, (depth is the radius of
// the hitbox)
Enemy::Enemy(float depth) {
  // Sets the depth of the enemy
  this->depth = 250;
  // Sets the tag (used for collisions)
  setTag("enemy");
}
// Default Constructor, which just sets the depth to 250 by default
//Enemy::Enemy() : Enemy(250){};
// Constructor which provides the depth & velocity for the enemy
Enemy::Enemy(float depth, sf::Vector2f velocity) {
  // Sets the depth to the depth provided
  this->depth = 250;
  // Same with the velocity
  this->velocity = velocity;
  // Sets the tag
  setTag("enemy");
}

Enemy::Enemy(float depth, sf::Vector2f velocity, sf::Texture* texture,
             sf::Vector2f position) {
  this->depth = 250;
  this->velocity = velocity;
  sprite.setTexture(*texture);
  sprite.setPosition(position);
  sprite.setOrigin(64, 64);
  setTag("enemy");
}
void Enemy::update(double timeElapsed, sf::RenderWindow* window) {
  sf::Vector2f currentPos = sprite.getPosition();
  sprite.setPosition(currentPos.x + timeElapsed * velocity.x,
                     currentPos.y + timeElapsed * velocity.y);
  window->draw(sprite);
}
void Enemy::getHit(Entity** objectsToBeDrawn, int* numObjects, int* index) {
  this->enemyLife -= 1;
  if (this->enemyLife <= 0) {
    shiftArray(objectsToBeDrawn, numObjects, index);
    delete this;
  }
}

void Enemy::shoot(Entity** objectsToBeDrawn, int* numObjects, int* maxObjects,
                  double totalTime) {
  if (totalTime - timeBulletFired > 0.25) {
    if (*numObjects < *maxObjects) {
      // std::cout << "Spawning Bullets";
      objectsToBeDrawn[*numObjects] = new EnemyBullet(
          sprite.getPosition(),
          sf::Vector2f(-1 / sqrt(2) * 0.25, 1 / sqrt(2) * 0.25));
      *numObjects += 1;
      objectsToBeDrawn[*numObjects] =
          new EnemyBullet(sprite.getPosition(),
                          sf::Vector2f(1 / sqrt(2) * 0.25, 1 / sqrt(2) * 0.25));
      *numObjects += 1;
    } else {
      std::cout << "Too many entities!!!" << std::endl;
    }
    timeBulletFired = totalTime;
  }
}