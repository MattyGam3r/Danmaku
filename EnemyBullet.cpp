#include "EnemyBullet.h"

//The default constructor for the Enemy Bullet
EnemyBullet::EnemyBullet(sf::Vector2f startPosition,
                         sf::Vector2f bulletVelocity) {
  this->depth = 16;
  sprite.setPosition(startPosition);
  velocity = bulletVelocity;
  //Sets the bullet sprite to the image 'bull1.png'
  bulletSprite.loadFromFile("bull1.png");
  sprite.setTexture(bulletSprite);
  //Calls the default constructor for Bullet
  Bullet();
  //Sets the tag to 'enemybullet' (used for collisions)
  setTag("enemybullet");
}
