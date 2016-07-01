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
}

void HUD::eventHandler(Event& event)
{
    if(event.clicked)
    {
        sf::Vector2f mousePos = this->getInverseTransform().transformPoint(event.defaultPos);

        if(selectedBuilding == Buildings::None)
        {

            std::cout <<".";
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
                std::cout <<event.defaultPos.x <<"\t" <<event.defaultPos.y <<"\n";
                event.isOnMap = true;
                event.hexPos = new HexPosition(TileMap::convertToHexPos(event.mapPos));
            }
        }
        else
        {
            HexPosition pos = TileMap::convertToHexPos(event.mapPos);
            buildingQmutex.lock();
            buildingQ.push(new Building(selectedBuilding, pos));
            buildingQmutex.unlock();
            selectedBuilding = Buildings::None;
        }
    }
}

Building* HUD::getBuilding()
{
    Building* building = nullptr;
    buildingQmutex.lock();
    if(!buildingQ.empty())
    {
        building = buildingQ.front();
        buildingQ.pop();
    }
    buildingQmutex.unlock();
    return building;
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*background, states);
    target.draw(*barracksSample, states);
    target.draw(*treasurySample, states);
}

}
