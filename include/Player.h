#ifndef PLAYER_H
#define PLAYER_H
#include"vector"
#include"Building.h"
#include<iostream>
#include "Soldier.h"
#include "staff/Event.h"
using namespace netWars;
class Player: public sf::Drawable
{
    public:
        int soldiernum;
        int coinnum;
        std::vector <Building*> bld;
        std::vector <Soldier*> sld;
        Player();
         ~Player();
        void getType(int i);
        int addBuilding(Building*);
        bool eventHandler(Event&);
        bool isCellEmpty(netWars::HexPosition pos);
        void timing(int i);
    protected:
    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PLAYER_H
