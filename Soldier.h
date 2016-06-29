#ifndef SOLDIER_H
#define SOLDIER_H
#include "Cell.h"

class Soldier
{
    public:
        Cell pos;
        int life;
        int strength;
        Cell way[100];
        int size;
        int x;
        int y;
        Soldier();
        virtual ~Soldier();
        void move();
        void attack(Cell maghsad,Soldier* enemy);
    protected:
    private:
};

#endif // SOLDIER_H
