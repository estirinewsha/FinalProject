#ifndef PLAYER_H
#define PLAYER_H
#include"vector"
#include"Building.h"
#include<iostream>
#include "Soldier.h"
using namespace netWars;
class Player: public sf::Drawable, public sf::Transformable
{
    public:
        int soldiernum;
        int coinnum;
        std::vector <Building> bld;
        std::vector <Soldier> sld;
        Player();
         ~Player();
        void getType(int i);
        bool addnew(int x,int y,int type);
        bool eventHandler(Event&,sf::RenderWindow *window,bool *b);
        void timing(int i);
    protected:
    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PLAYER_H
