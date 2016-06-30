#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Configuration.h"
#include "Coordinate/HexFractionalPosition.h"

namespace netWars
{

const float s = 1.f;        //sin(90)
const float r = 0.86602540f;//sin(60)
const float h = 0.5f;       //sin(30)
const float z = 0.f;        //sin( 0)
const float PI = 3.14;      //PI Number

class Cell : public sf::Drawable, public sf::Transformable
{
    int radious;
    HexPosition pos;
    sf::Sprite *sprite;
    #ifdef DEBUG
    sf::VertexArray vertex;
    sf::Text text;
    #endif // DEBUG
public:
    enum type : int {Water, Dirt, Grass, Barracks};
    Cell(HexPosition pos, type t, int radious);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

}

#endif // CELL_H_INCLUDED
