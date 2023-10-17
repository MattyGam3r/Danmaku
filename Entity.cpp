#include "Entity.h"

//Returns the tag of the entity (used for collisions)
std::string Entity::getTag() { return tag; }

//Sets the tag to a string
void Entity::setTag(std::string name) { this->tag = name; }

//Returns a timer, which is useful for complex bullet patterns
sf::Time Entity::getTime() { return timer; }

//Returns the sprite
sf::Sprite Entity::getSprite() { return sprite; }

//Returns the depth
float Entity::getDepth() { return depth; }

//This function shifts an array, where it removes the n'th object (denoted by index), then shifts all values down one
void Entity::shiftArray(Entity** objectsToBeDrawn, int* numObjects,
                        int* index) {
  for (int i = *index; i < *numObjects - 1; i++) {
    objectsToBeDrawn[i] = objectsToBeDrawn[i + 1];
  }
  *numObjects -= 1;
}
