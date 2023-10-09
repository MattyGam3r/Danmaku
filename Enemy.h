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
        void update(){

        }
};

#endif