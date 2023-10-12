#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"
#include "cmath"
#include <iostream>
class Bullet: public Entity{
    protected:
        double speed;
    public:
        void update(double timeElapsed, sf::RenderWindow* window){
            sf::Vector2f currentPos = sprite.getPosition();
            //std::cout << currentPos.y << " ";
            sprite.setPosition(currentPos.x + timeElapsed*velocity.x, currentPos.y + timeElapsed*velocity.y);
            window->draw(sprite);
        }
        //This is only for bullets which travel towards points, but still helpful
        sf::Vector2f getVelocityTowardsPoint(sf::Vector2f startingPoint, sf::Vector2f endPoint){
            double xdif = endPoint.x - startingPoint.x;
            double ydif = endPoint.y - startingPoint.y;
            double length = sqrt(pow(xdif,2)+pow(ydif,2));
            sf::Vector2f velocityTowardsPoint;
            velocityTowardsPoint.x = xdif/length;
            velocityTowardsPoint.y = ydif/length;
            return velocityTowardsPoint;
        }


};

#endif