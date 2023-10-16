#ifndef WAVE_H
#define WAVE_H
#include <iostream>
#include "Enemy.h"
#include "Entity.h"
class Wave{
    private:
        Enemy ** enemies;
        int numEnemies = 0;
        int maxEnemies = 100;
        int enemyTime;
    public:
        Wave(int maxEnemies){
            this->maxEnemies = maxEnemies;
            enemies = new Enemy*[maxEnemies];
        }
        Wave(){
            enemies = new Enemy*[100];
        }
        int getEnemyTime(){
            return enemyTime;
        }
        void setEnemyTime(int enemyTime){
            this->enemyTime = enemyTime;
        }

        void addEnemy(Enemy * enemy){
            std::cout << "adding enemy" << std::endl;
            if (numEnemies < maxEnemies){
                enemies[numEnemies] = enemy;
                numEnemies++;
            }
            else{
                std::cout << "Reached Max Enemies, Enemy Not Added" << std::endl;
            }
        }

        void SpawnEnemies(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, int* waveSpawned){
            
            for (int i = 0; i < numEnemies; i++){

                if (*numObjects < *maxObjects){
                    std::cout << "Spawning Objects ";
                    objectsToBeDrawn[*numObjects] = enemies[i];
                    *numObjects += 1;
                }
                else{
                    std::cout << "Too many entities!!! " << std::endl;
                }
            }
            *waveSpawned += 1;
        }
};

#endif