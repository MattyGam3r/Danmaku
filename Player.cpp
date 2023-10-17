#include "Player.h"

#include <SFML/Graphics.hpp>
// Default Constructor for Player
Player::Player() {
  playerTexture = new sf::Texture;
  player = new sf::Sprite;
  playerTexture->loadFromFile("player.png");
  player->setTexture(*playerTexture);
  player->setPosition(sf::Vector2f(240, 500));
  // Sets the origin of the player to be directly in the middle of the sprite
  player->setOrigin(sf::Vector2f(0, 0));
  // Sets the speed by default to be 4.5
  speed = 4.5;
  timeBulletFired = -1;
  // Sets the healthPoints to 3
  healthPoints = 3;
  depth = 10;

    //Making the player health variable
  font.loadFromFile("Christmas Bell.otf");
  //Sets the font of the player health text to the font loaded from the file
  playerHealthText.setFont(font);
  //Sets the colour of the text to red
  playerHealthText.setFillColor(sf::Color::Red);
  playerHealthText.setString("Player Health: " + std::to_string(healthPoints));
  playerHealthText.setCharacterSize(40);
  playerHealthText.setPosition(0, 0);
}

// Draws the player to the render window
void Player::draw(sf::RenderWindow* window) {
  // draws the player to the screen
  window->draw(*player);
  // Draws the players health variable to the top left of the screen
  window->draw(playerHealthText);
}
// Returns the players position
sf::Vector2f Player::getPosition() { return this->getPosition(); }
// Movement
// Moves the player right by the speed variable
void Player::move_right(double timeElapsed) {
  if (player->getPosition().x < 460) {
    player->setPosition(player->getPosition().x + speed * timeElapsed,
                        player->getPosition().y);
  }
}
// Moves the player leftwards by the speed variable
void Player::move_left(double timeElapsed) {
  if (player->getPosition().x > 0) {
    player->setPosition(player->getPosition().x - speed * timeElapsed,
                        player->getPosition().y);
  }
}
// Moves the player upwards by the speed variable
void Player::move_up(double timeElapsed) {
  if (player->getPosition().y > 0) {
    player->setPosition(player->getPosition().x,
                        player->getPosition().y - speed * timeElapsed);
  }
}
// Moves the player downwards by the speed variable
void Player::move_down(double timeElapsed) {
  if (player->getPosition().y < 600) {
    player->setPosition(player->getPosition().x,
                        player->getPosition().y + speed * timeElapsed);
  }
}
void Player::shoot(Entity** objectsToBeDrawn, int* numObjects, int* maxObjects,
                   double totalTime) {
  if (totalTime - timeBulletFired > 0.25) {
    if (*numObjects < *maxObjects) {
      // std::cout << "Spawning Bullets";
      objectsToBeDrawn[*numObjects] = new PlayerBullet(player->getPosition());
      *numObjects += 1;
    } else {
      std::cout << "Too many entities!!!" << std::endl;
    }
    timeBulletFired = totalTime;
  }
}

sf::Sprite* Player::getSprite() { return player; }
double Player::getDepth() { return depth; }

void Player::getHit() {
  this->healthPoints -= 1;
  playerHealthText.setString("Player Health: " + std::to_string(healthPoints));
}
// Gets the players health
int Player::getHealth() { return healthPoints; }
// Shooting and Bomb
void Player::setSpeed(float speed) { this->speed = speed; }
float Player::getSpeed() { return speed; }