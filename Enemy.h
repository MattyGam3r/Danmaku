#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
class Enemy : Entity{
    private:
        sf::Vector2f startPosition;
        sf::Vector2f endPosition;
    public:
        Enemy(float depth){
            this->depth = depth;
        }
        Enemy(float depth, sf::Vector2f velocity){
            this->depth = depth;
            this->velocity = velocity;
        }
        Enemy(float depth, sf::Vector2f velocity, sf::Texture *texture, sf::Vector2f position){
            this->depth = depth;
            this->velocity = velocity;
            sprite.setTexture(*texture);
            sprite.setPosition(position);
        }
        void update(double timeElapsed,sf::RenderWindow* window){
            sf::Vector2f currentPos = sprite.getPosition();
            sprite.setPosition(currentPos.x + timeElapsed*velocity.x, currentPos.y + timeElapsed*velocity.y);
            window->draw(sprite);
        }
};

#endif