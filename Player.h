#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
class Player{
    private:
        sf::Texture* playerTexture;
        sf::Sprite* player;
    public:
    //Default Constructor for Player
        Player(){
            playerTexture = new sf::Texture;
            player = new sf::Sprite;
            playerTexture->loadFromFile("player.png");
            player->setTexture(*playerTexture);
            player->setPosition(sf::Vector2f(1,1));
            player->setOrigin(sf::Vector2f(1,1));
        }
        void draw(sf::RenderWindow* window){
            window->draw(*player);
        }
        
        //Movement
        void move_right(float speed){
            sf::Vector2f position = player->getPosition();
            position.x += speed;
            player->setPosition(position);
        }
        void move_left(float speed){
            sf::Vector2f position = player->getPosition();
            position.x -= speed;
            player->setPosition(position);
        }
        void move_up(float speed){
            sf::Vector2f position = player->getPosition();
            position.y -= speed;
            player->setPosition(position);
        }
        void move_down(float speed){
            sf::Vector2f position = player->getPosition();
            position.y += speed;
            player->setPosition(position);
        }
        
        
};

#endif