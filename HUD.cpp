#include "HUD.h"
#include "Configuration.h"
#include <iostream>

namespace netWars
{

HUD::HUD()
{
    background = new sf::RectangleShape(sf::Vector2f(360, 92));
    background->setFillColor(sf::Color::White);
    treasurySample=new sf::Sprite(Configuration::textures.get(Configuration::TexTreasury));
    treasurySample->setPosition(sf::Vector2f(100, 20));
    barracksSample = new sf::Sprite(Configuration::textures.get(Configuration::TexBarracks));
    barracksSample->setPosition(sf::Vector2f(10, 20));
    addbuilding=false;
    addcoor=false;
    buildingnum=0;
}

void HUD::eventHandler(Event& event)
{
    if(event.clicked)
    {
        sf::Vector2f mousePos = this->getInverseTransform().transformPoint(event.mousePos);

        if(background->getGlobalBounds().contains(mousePos))
        {
            if(barracksSample->getGlobalBounds().contains(mousePos))
            {
                std::cout <<mousePos.x <<"\t" <<mousePos.y <<"\n";
                std::cout <<"Clicked On Barracks\n";

                selectedBuilding = Buildings::Barracks;
                addbuilding=true;
            }
            else if(treasurySample->getGlobalBounds().contains(mousePos))
            {
                std::cout <<mousePos.x <<"\t" <<mousePos.y <<"\n";
                std::cout <<"Clicked On treasury\n";

                selectedBuilding = Buildings::Treasury;
                addbuilding=true;
            }
        }
        else
        {

            std::cout <<event.mousePos.x <<"\t" <<event.mousePos.y <<"\n";
            event.isOnMap = true;
            selectedBuilding = Buildings::None;
        }

    }
    //std::cout<<'\n'<<selectedBuilding<<'\n';
}
void HUD::addBarCoor(int x,int y,int i){
    bars[i].setPosition(sf::Vector2f(x, y));
}
void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*background, states);
    target.draw(*barracksSample, states);
    target.draw(*treasurySample, states);
}

}
