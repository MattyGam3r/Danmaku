#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
class PlayerBullet : public Bullet{
    private:
        sf::Texture bulletSprite;

    public:
        PlayerBullet(sf::Vector2f startPos){
            this->depth = 1;
            sprite.setPosition(startPos);
            velocity = sf::Vector2f(0,-1);
            bulletSprite.loadFromFile("bull1.png");
            sprite.setTexture(bulletSprite);
        }
        PlayerBullet(){
            velocity = sf::Vector2f(0.01,0);
            bulletSprite.loadFromFile("bull1.png");
            sprite.setTexture(bulletSprite);
            this->depth = 1;
        }
        void SpawnBullet(sf::Sprite * sprite){
            PlayerBullet(sprite->getPosition());
        }
        void hit(Enemy * enemy){
            enemy->takeDamage();
        };

};


#endif