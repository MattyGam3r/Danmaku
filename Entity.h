#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Entity{
    protected:
        //The sprite of the entity
        sf::Sprite sprite;
        sf::Vector2f velocity;
        //The radius of the item itself, this is used for hitbox calculations
        float depth;
        sf::Time timer;
        std::string tag;

    public:
        //Returns the tag of the entity (used for collisions)
        std::string getTag();

        //Sets the tag to a string
        void setTag(std::string name);
        
        //Returns a timer, which is useful for complex bullet patterns
        sf::Time getTime();

        //This virtual function must be shared across all classes which inherit from Entity
        //Every frame this function will be called, which updates the position of each Entity, then lastly draws themself to the window parsed in
        virtual void update(double timeElapsed, sf::RenderWindow* window) = 0;
        //This is called when an object collides with an object *(usually the player).
        virtual void getHit(Entity ** objectsToBeDrawn, int * numObjects, int * index) = 0;

        //Returns the sprite
        sf::Sprite getSprite();
        
        //Returns the depth
        float getDepth();

        //This function shifts an array, where it removes the n'th object (denoted by index), then shifts all values down one
        void shiftArray(Entity ** objectsToBeDrawn, int * numObjects, int * index);

        //PURELY FOR ENEMY ONLY!
        virtual void shoot(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, double totalTime){
            std::cout << "shoot wrong";
        }

};
#endif