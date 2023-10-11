#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Bullet.h"
class EnemyBullet : public Bullet{
    private:

    public:
        //When the bullet touches smth, this gets called
        void hit();


};


#endif