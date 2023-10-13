#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
class Entity{
    protected:
        //The sprite of the entity
        sf::Sprite sprite;
        sf::Vector2f velocity;
        //The radius of the item itself, this is used for hitbox calculations
        float depth;
        static sf::Time timer;
        std::string tag;

    public:
        std::string getTag(){
            return tag;
        }
        void setTag(std::string name){
            this->tag = name;
        }
        sf::Time getTime(){
            return timer;
        }
        virtual void update(double timeElapsed, sf::RenderWindow* window) = 0;
        virtual void getHit(Entity ** objectsToBeDrawn, int * numObjects, int * index) = 0;
        sf::Sprite getSprite(){
            return sprite;
        }
        float getDepth(){
            return depth;
        }

        void shiftArray(Entity ** objectsToBeDrawn, int * numObjects, int * index){
            for (int i = * index; i < *numObjects-1; i++){
                objectsToBeDrawn[i] = objectsToBeDrawn[i+1];
            }
            *numObjects -= 1;
            *index -= 1;
        }

};
#endif