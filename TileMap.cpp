#include "staff/TileMap.h"

namespace netWars
{

TileMap::TileMap(MAPS mapName, int radious)
{
    if(mapName == TileMap::SAMPLE)
    {
        const int T = 7;
        for(int i=-T;i<=T;i++)
        {
            for(int j=(i<0 ? abs(i)-T : -T);j<=(i<0 ? T-abs(i)-i : T-i);j++)
            {
                hexs.push_back( new Cell(HexPosition(i,j), Cell::Grass, radious) );
            }
        }
    }

}


TileMap::~TileMap()
{
    for(auto cell : hexs)
    {
            delete cell;
    }
}
void TileMap::eventHandler(Event& event)
{
   /* if(event.clicked)
    {
        sf::Vector2f mousePos =this->getInverseTransform().transformPoint(event.mousePos);
        if(hud->addcoor){
           // hud->xPose=mousePos.x;
            //hud->yPose=mousePos.x;
            //std::cout<<"this"<<hud->xPose<<'\n'<<hud->yPose<<'\n';
            hud->addbuilding=true;
            hud->addcoor=false;
            std::cout<<"adding coor"<<'\n';
        }
    }*/

}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for(unsigned int i=0;i<hexs.size();i++)
    {
        target.draw(*hexs[i]);
    }

}

HexPosition TileMap::convertToHexPos(sf::Vector2f p)
{
    sf::Vector2f pt(p.x/(71), p.y/(71));
    double q = (sqrt(3.0)/3) * pt.x + (-1.0/3) * pt.y;
    double r = 0.0 * pt.x + (2.0/3) * pt.y;

    return HexFractionalPosition(q, r, -q - r);
}

}
