//PLAYER CLASS
//This is the class which the player control
//The player can move and shoot, when the healthPoints reaches 0, the game ends


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
        sf::Font font;
        sf::Text playerHealthText;
    public:
    //Default Constructor for Player
        Player();
    //Draws the player to the render window, aswell as the health value of the player
        void draw(sf::RenderWindow* window);
        //Returns the position of the player
        sf::Vector2f getPosition();
        //Updates the player's position to the right
        void move_right(double timeElapsed);
        //Updates the player's position to the left
        void move_left(double timeElapsed);
        //Updates the player's position upwards
        void move_up(double timeElapsed);
        //Updates the player's position downwards
        void move_down(double timeElapsed);

        //This is called when the player presses 'Z', it spawns a bullet, and adds it to the 'objectsToBeDrawn' array
        void shoot(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, double totalTime);

        //Returns the sprite of the player
        sf::Sprite * getSprite();
        //Returns the depth of the player (used for hitboxes)
        double getDepth();

        //This is caleed when the player collides with an Enemy, or Bullet
        void getHit();
        //Gets the players health
        int getHealth();
        //Sets the speed variable
        void setSpeed(float speed);
        //Returns the speed variable
        float getSpeed();

        
};

#endif