#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Bullet.h"
class EnemyBullet : public Bullet{
    private:
        sf::Texture bulletSprite;
        
    public:
        //When the bullet touches smth, this gets called
        void hit();
        EnemyBullet(sf::Vector2f startPosition, sf::Vector2f bulletVelocity){
            this->depth = 16;
            sprite.setPosition(startPosition);
            velocity = bulletVelocity;
            bulletSprite.loadFromFile("bull1.png");
            sprite.setTexture(bulletSprite);
            Bullet();
            setTag("enemybullet");
        }



};


#endif