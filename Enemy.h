#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
class Enemy : public Entity{
    private:
        sf::Vector2f startPosition;
        sf::Vector2f endPosition;
        float enemyLife = 10;
    public:
        Enemy(float depth){
            this->depth = 128;
            setTag("enemy");
        }
        Enemy(float depth, sf::Vector2f velocity){
            this->depth = 128;
            this->velocity = velocity;
            setTag("enemy");
            
        }
        Enemy(float depth, sf::Vector2f velocity, sf::Texture *texture, sf::Vector2f position){
            this->depth = 128;
            this->velocity = velocity;
            sprite.setTexture(*texture);
            sprite.setPosition(position);
            sprite.setOrigin(64,64);
            setTag("enemy");
        }
        void update(double timeElapsed,sf::RenderWindow* window){
            sf::Vector2f currentPos = sprite.getPosition();
            sprite.setPosition(currentPos.x + timeElapsed*velocity.x, currentPos.y + timeElapsed*velocity.y);
            window->draw(sprite);
        }
        void getHit(Entity ** objectsToBeDrawn, int * numObjects, int * index){
            this->enemyLife -= 1;
            if (this->enemyLife <= 0){
                shiftArray(objectsToBeDrawn, numObjects, index);
                delete this;
            }
        }
};


#endif