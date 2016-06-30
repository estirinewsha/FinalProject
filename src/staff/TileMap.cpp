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
    hud=new HUD[1];
    player=new Player[1];
    treasurySample=new sf::Sprite(Configuration::textures.get(Configuration::TexTreasury));
    barracksSample = new sf::Sprite(Configuration::textures.get(Configuration::TexBarracks));
    barracksSample->setPosition(sf::Vector2f(100, 200));
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
    if(event.clicked)
    {
        sf::Vector2f mousePos =this->getInverseTransform().transformPoint(event.mapPos);
        if(hud->addcoor){
           // hud->xPose=mousePos.x;
            //hud->yPose=mousePos.x;
            //std::cout<<"this"<<hud->xPose<<'\n'<<hud->yPose<<'\n';
            hud->addbuilding=true;
            hud->addcoor=false;
            std::cout<<"adding coor"<<'\n';
        }
    }

}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(hud->addbuilding){
                int x=hud->xPose;
                int y=hud->yPose;
                if(!player->addnew(100000,1000000,hud->selectedBuilding))
                    std::cout<<"nomoney"<<'\n';
                //this->addnewbar(hud->xPose,hud->yPose);
                else{
                    sf::RectangleShape r;
                    r.setPosition( x , y-20 );
                    r.setFillColor(sf::Color::Green);
                    sf::Clock cl;
                    hud->bars.push_back(r);
                    hud->clock.push_back(cl);
                    hud->addbuilding=false;
                    hud->addcoor=true;
                    hud->buildingnum++;
            std::cout<<hud->xPose<<'\n'<<hud->yPose<<'\n';
                    std::cout<<"adding coor"<<'\n';
                }

        }
    for(unsigned int i=0;i<hexs.size();i++)
    {
        target.draw(*hexs[i]);
    }
    for(int i=0;i<player->bld.size();i++){
        //std::cout<<"s"<<player->bld.size()<<'\n'<<player->bld[i].type<<'\n'<<player->bld[i].x<<'\n';
        if(player->bld[i].type==1){
            barracksSample->setPosition(convertToHexPos(sf::Vector2f(player->bld[i].x, player->bld[i].y)));
            target.draw(*barracksSample);
        }
        else if(player->bld[i].type==2){
            treasurySample->setPosition(convertToHexPos(sf::Vector2f(player->bld[i].x, player->bld[i].y)));
            target.draw(*treasurySample);
        }
        //std::cout<<"draw"<<player->bld[i].x<<player->bld[i].x<<'\n';

    }
    for(int i=0;i<hud->bars.size();i++){
        if(!(i==hud->bars.size()&&hud->addcoor)){
            int x=hud->clock[i].getElapsedTime().asSeconds();
            hud->bars[i].setSize(sf::Vector2f(x, 20));
            //hud->bars[i].setPosition(player->bld[i].x, player->bld[i].y);
            target.draw(hud->bars[i]);
        }
    }
    for(int i=0;i<hud->clock.size();i++){
        if(hud->clock[i].getElapsedTime().asSeconds()>60){
            hud->clock[i].restart();
           // hud->bars[i].setPosition(player->bld[i].x, player->bld[i].y);
            player->getType(i);
        }
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
