#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
class Entity{
    protected:
        //The sprite of the entity
        sf::Sprite sprite;
        sf::Vector2f velocity;
        //The radius of the item itself, this is used for hitbox calculations
        float depth;
        static sf::Time timer;

    public:
        sf::Time getTime(){
            return timer;
        }
        virtual void update(double timeElapsed, sf::RenderWindow* window) = 0;
        sf::Sprite getSprite(){
            return sprite;
        }
        float getDepth(){
            return depth;
        }

};
#endif