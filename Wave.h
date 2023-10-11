#ifndef WAVE_H
#define WAVE_H
#include <iostream>
#include "Enemy.h"
#include "Entity.h"
class Wave{
    private:
        Enemy * enemies;
        int numEnemies;
        int enemyTime;
    public:
        Wave(Enemy * enemies, int enemyTime, int numEnemies){
            this->enemies = enemies;
            this->enemyTime = enemyTime;
            this->numEnemies = numEnemies;
        }
        Wave(Enemy * enemies, int enemyTime){
            this->enemies = enemies;
            this->enemyTime = enemyTime;
            this->numEnemies = 1;
        }
        int getEnemyTime(){
            return enemyTime;
        }
        void setEnemyTime(int enemyTime){
            this->enemyTime = enemyTime;
        }

        void SpawnEnemies(Entity ** objectsToBeDrawn, int * numObjects, int * maxObjects, int* waveSpawned){
            
            for (int i = 0; i < numEnemies; i++){

                if (numObjects < maxObjects){
                    std::cout << "Spawning Objects";
                    objectsToBeDrawn[*numObjects] = &enemies[i];
                    *numObjects += 1;
                    *waveSpawned += 1;
                }
                else{
                    std::cout << "Too many entities!!!" << std::endl;
                }
            }
        }
};

#endif