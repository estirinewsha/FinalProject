#include "staff/Cell.h"

#include <iostream>
#include <string>

namespace netWars
{

Cell::Cell(HexPosition pos, type t, int radious) : pos(pos)
#ifdef DEBUG
, vertex(sf::LinesStrip, 7)
#endif // DEBUG
{
    sprite = new sf::Sprite(Configuration::textures.get(Configuration::TexGrass));
    sprite->setOrigin(sprite->getGlobalBounds().width/2, sprite->getGlobalBounds().height/2);
    this->radious = radious;
    #ifdef DEBUG
    text.setString(std::to_string(pos.q)+","+std::to_string(pos.r));
    text.setFont(Configuration::font);
    text.setCharacterSize(40);
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);

    vertex[0].position = sf::Vector2f(  z*radious, -s*radious);
    vertex[1].position = sf::Vector2f( +r*radious, -h*radious);
    vertex[2].position = sf::Vector2f( +r*radious, +h*radious);
    vertex[3].position = sf::Vector2f(  z*radious, +s*radious);
    vertex[4].position = sf::Vector2f( -r*radious, +h*radious);
    vertex[5].position = sf::Vector2f( -r*radious, -h*radious);
    vertex[6].position = sf::Vector2f(  z*radious, -s*radious);
    #endif // DEBUG
    this->setPosition(pos);
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *=getTransform();

    target.draw(*sprite, states);
    #ifdef DEBUG
    target.draw(vertex, states);
    target.draw(text, states);
    #endif // DEBUG
}

}
