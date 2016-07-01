#include "Building.h"

Building::Building(int type, netWars::HexPosition pos) : type(type), pos(pos)
{
    bar.setFillColor(sf::Color::Green);
    if(type == 0)
    {
        sprite = new sf::Sprite(Configuration::textures.get(Configuration::TexCastle));
        //sprite->setPosition(convertToHexPos(sf::Vector2f(100, 200)));
    }
    else if(type == 1)
    {
        sprite = new sf::Sprite(Configuration::textures.get(Configuration::TexBarracks));
    }
    else if(type == 2)
    {
        sprite = new sf::Sprite(Configuration::textures.get(Configuration::TexTreasury));
    }
    this->setPosition(pos);
    sprite->setOrigin(sprite->getGlobalBounds().width/2, sprite->getGlobalBounds().height/2);
    sprite->setPosition(sf::Vector2f(0, 0));
    bar.setPosition(-40, -50);
}

int Building::setSize(int x)
{
    bar.setSize(sf::Vector2f(x, 20));
}

void Building::add(int t)
{
    ;
}

int Building::getType()
{
    return type;
}

int Building::getClock()
{
    int second = clock.getElapsedTime().asSeconds();
    bar.setSize(sf::Vector2f(second, 20));
    if(second > 60)
        clock.restart();
    return second;
}

netWars::HexPosition Building::getPos()
{
    return pos;
}

void Building::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    states.transform *= getTransform();

    target.draw(*sprite, states);
    target.draw(bar, states);
}
