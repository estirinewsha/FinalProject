#include "Player.h"
#include "Coordinate/HexPosition.h"

bool Player::addBuilding(Building* building)
{
    if(coinnum>100)
    {
        bld.push_back(building);
        std::cout <<",,,,,,,,\n";
        coinnum-=100;
        return true;
    }
    else
    {
        return false;
    }
}

Player::Player()
{
    coinnum = 1000;
    soldiernum=0;

    bld.push_back(new Building(0, netWars::HexPosition(2,2)));///Castle

}

void Player::getType(int i)
{
    if(bld[i]->getType()==1)
        soldiernum+=1;
    else if(bld[i]->getType()==2)
        coinnum+=10;
}

Player::~Player()
{
    //dtor
}

bool Player::eventHandler(Event& event)
{
    if(event.clicked&&event.isOnMap)
    {
        ///Check for clicked on Building or Soldier

    }
    for(Building* building : bld)
    {
        if(building->getClock()>60)
        {
            if(building->getType()==1)
            {
                soldiernum++;
                sld.push_back(new Soldier(building->getPos()));
            }
            else if(building->getType()==2)
            {
                coinnum+=20;
            }
        }
    }
    return false;
}

bool Player::isCellEmpty(netWars::HexPosition pos)
{
     for(Building* building : bld)
     {
         if(building->getPos() == pos)
            return false;
     }
     for(Soldier* soldier : sld)
     {
         if(soldier->location == pos)
            return false;
     }
     return true;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(Building* building : bld)
    {
        target.draw(*building);
    }
    for(Soldier* soldier : sld)
    {
        target.draw(*soldier);
    }
}
