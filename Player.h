#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerBullet.h"
#include <SFML/Graphics.hpp>
class Player{
    private:
        sf::Texture* playerTexture;
        sf::Sprite* player;
        float speed;
        double timeBulletFired;
        int healthPoints;
        double depth;
    public:
    //Default Constructor for Player
        Player(){
            playerTexture = new sf::Texture;
            player = new sf::Sprite;
            playerTexture->loadFromFile("player.png");
            player->setTexture(*playerTexture);
            player->setPosition(sf::Vector2f(240,500));
            player->setOrigin(sf::Vector2f(0,0));
            speed = 4.5;
            timeBulletFired = -1;
            healthPoints = 3;
            depth = 10;
        }
        void draw(sf::RenderWindow* window){
            window->draw(*player);
        }
        sf::Vector2f getPosition(){
            return this->getPosition();
        }
        //Movement
        void move_right(double timeElapsed){
            if (player->getPosition().x < 460){
                player->setPosition(player->getPosition().x+speed*timeElapsed, player->getPosition().y);
            }
        }
        void move_left(double timeElapsed){
            if (player->getPosition().x > 0){
                player->setPosition(player->getPosition().x-speed*timeElapsed, player->getPosition().y);
            }
        }
        void move_up(double timeElapsed){
            if (player->getPosition().y > 0){
                player->setPosition(player->getPosition().x, player->getPosition().y-speed*timeElapsed);
            }
        }
        void move_down(double timeElapsed){
            if (player->getPosition().y < 600){
                player->setPosition(player->getPosition().x, player->getPosition().y+speed*timeElapsed);
            }
        }
        void shoot(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, double totalTime){
            if (totalTime - timeBulletFired > 0.25){
                if (*numObjects < *maxObjects){
                    //std::cout << "Spawning Bullets";
                    objectsToBeDrawn[*numObjects] = new PlayerBullet(player->getPosition());
                    *numObjects += 1;
                }
                else{
                    std::cout << "Too many entities!!!" << std::endl;
                }
                timeBulletFired = totalTime;
            }
        }

        sf::Sprite * getSprite(){
            return player;
        }
        double getDepth(){
            return depth;
        }

        void getHit(){
            this->healthPoints -= 1;
        }
        //Shooting and Bomb
        void setSpeed(float speed){
            this->speed = speed;
        }
        float getSpeed(){
            return speed;
        }

        
};

#endif