#include "Soldier.h"

Soldier::Soldier ():x(0),y(0),life(10),strength(5),size(100){
        int i=99;
        while(i>=0){
            way[i].pos.x=i*20;
            way[i].pos.y=i*30;
            i--;
        }
    }
Soldier::~Soldier()
{
    //dtor
}
 void Soldier::move(){
        static int i=1,x0=x,y0=y;
        if(size!=0)
        {
            if(x!=way[i].x)
            {
            float m=(y0-way[i].y)/(x0-way[i].x);
            if(way[i].x>x)
                x+=1;
            else
                x-=1;
                y=m*(x-way[i].x)+way[i].y;

                cout<<"m:"<<m<<endl;}
            if(x==way[i].x){
                x0=way[i].x;
                y0=way[i].y;
                i++;
            }
        }
        if(i==size)
        {
            i=0;
            size=0;
        }
    }
    void Soldier::attack(Cell maghsad,Soldier* enemy){
        move();
        if(x==maghsad.x && y==maghsad.y)
        {
            life-=enemy->strength;
            enemy->life-=strength;
        }
    }
