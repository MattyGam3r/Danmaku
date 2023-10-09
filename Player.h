#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
class Player{
    private:
        sf::Texture* playerTexture;
        sf::Sprite* player;
        float speed;
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
        }
        void draw(sf::RenderWindow* window){
            window->draw(*player);
        }
        
        //Movement
        void move_right(double timeElapsed){
            player->setPosition(player->getPosition().x+speed*timeElapsed, player->getPosition().y);
        }
        void move_left(double timeElapsed){
            player->setPosition(player->getPosition().x-speed*timeElapsed, player->getPosition().y);
        }
        void move_up(double timeElapsed){
            player->setPosition(player->getPosition().x, player->getPosition().y-speed*timeElapsed);
        }
        void move_down(double timeElapsed){
            player->setPosition(player->getPosition().x, player->getPosition().y+speed*timeElapsed);
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