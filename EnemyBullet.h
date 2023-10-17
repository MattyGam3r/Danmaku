//ENEMY BULLET CLASS
//All bullets that are fired by enemies are controlled by this class
//Only can collide with the player (which reduces health points of the player)
//Destructs itself on collision with player


#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Bullet.h"
class EnemyBullet : public Bullet{
    private:
    
        sf::Texture bulletSprite;
        
    public:
        //When the bullet touches smth, this gets called
        void hit();
        EnemyBullet(sf::Vector2f startPosition, sf::Vector2f bulletVelocity);


};


#endif