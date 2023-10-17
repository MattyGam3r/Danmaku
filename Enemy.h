//ENEMY CLASS:
//Base class which all sub-enemies and bosses inherit from
//Has a start position, end position, enemylife, and time bullet fired

#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "EnemyBullet.h"
class Enemy : public Entity{
    protected:
        sf::Vector2f startPosition;
        sf::Vector2f endPosition;
        //Enemy Life (how many bullets can the enemy take before it's destroyed)
        float enemyLife = 3;
        //The last time the bullet was fired
        float timeBulletFired = 0;
    public:

        //Constructor which provides the depth of the enemy, (depth is the radius of the hitbox)    
        Enemy(float depth);
        //Default Constructor, which just sets the depth to 250 by default
        Enemy(): Enemy(250){};
        //Constructor which provides the depth & velocity for the enemy
        Enemy(float depth, sf::Vector2f velocity);
        Enemy(float depth, sf::Vector2f velocity, sf::Texture *texture, sf::Vector2f position);
        void update(double timeElapsed,sf::RenderWindow* window);
        void getHit(Entity ** objectsToBeDrawn, int * numObjects, int * index);
        virtual void shoot(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, double totalTime);
};


#endif