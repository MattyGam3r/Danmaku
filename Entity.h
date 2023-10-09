#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
class Entity{
    protected:
        sf::Sprite sprite;
        sf::Vector2f velocity;
        float depth;
    public:
        virtual void update(double timeElapsed, sf::RenderWindow* window) = 0;
        

};
#endif