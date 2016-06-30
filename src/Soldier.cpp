#include "Soldier.h"

#include "Configuration.h"

Soldier::Soldier(netWars::HexPosition loc) :location(loc), sprite (netWars::Configuration::textures.get(netWars::Configuration::TexSoldier))
{
    life = 10;
    strength = 5;
    size = 0;
    moving = false;
    fight = false;
    upDown = false;
    leftRight = false;
    deg = 0;
    x=((sf::Vector2f)loc).x;
    y=((sf::Vector2f)loc).y;
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    this->setPosition(location);
}
   /* void Soldier:: setWay(vector w){
        way=w;
        size=w.length();
    }*/
void Soldier:: move(){
        static int i=1,x0=x,y0=y;
        moving=1;
        if(size!=0)
        {
            if(x!=((sf::Vector2f)way[i]).x)
            {
                float m=(y0-((sf::Vector2f)way[i]).y)/(x0-((sf::Vector2f)way[i]).x);
                deg=atan(m);
                if(((sf::Vector2f)way[i]).x>x){
                    x+=1;
                    leftRight=1;
                }
                else{
                    x-=1;
                    leftRight=0;
                }
                if(((sf::Vector2f)way[i]).y>y)
                    upDown=0;
                else
                    leftRight=1;
                y=m*(x-((sf::Vector2f)way[i]).x)+((sf::Vector2f)way[i]).y;
            }
            if(x==((sf::Vector2f)way[i]).x){
                x0=((sf::Vector2f)way[i]).x;
                y0=((sf::Vector2f)way[i]).y;
                i++;
            }
        }
        if(i==size)
        {
            i=0;
            size=0;
            moving=0;
        }
    }
void Soldier:: attack(netWars::HexPosition dest,Soldier* enemy){
    move();
    if(x==((sf::Vector2f)dest).x && y==((sf::Vector2f)dest).y)
    {
        fight=1;
        life-=enemy->strength;
        enemy->life-=strength;
    }
}

void Soldier::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // draw the vertex array
    target.draw(sprite, states);
}
