#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "EnemyBullet.h"
class Enemy : public Entity{
    private:
        sf::Vector2f startPosition;
        sf::Vector2f endPosition;
        float enemyLife = 10;
        float timeBulletFired = 0;
    public:
        Enemy(float depth){
            this->depth = 250;
            setTag("enemy");
        }
        Enemy(float depth, sf::Vector2f velocity){
            this->depth = 250;
            this->velocity = velocity;
            setTag("enemy");
            
        }
        Enemy(float depth, sf::Vector2f velocity, sf::Texture *texture, sf::Vector2f position){
            this->depth = 250;
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

        void shoot(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, double totalTime){
            if (totalTime - timeBulletFired > 0.25){
                if (*numObjects < *maxObjects){
                    //std::cout << "Spawning Bullets";
                    objectsToBeDrawn[*numObjects] = new EnemyBullet(sprite.getPosition(), sf::Vector2f(0,0.25));
                    *numObjects += 1;
                }
                else{
                    std::cout << "Too many entities!!!" << std::endl;
                }
                timeBulletFired = totalTime;
            }
        }
};


#endif