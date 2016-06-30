#ifndef SOLDIER_H
#define SOLDIER_H
#include "Coordinate/HexPosition.h"
#include <SFML/Graphics.hpp>
using namespace netWars;
class Soldier : public sf::Drawable, public sf::Transformable
{
public:
    HexPosition location;
    int life;
    int strength;
    std::vector <HexPosition> way;
    int size;
    bool moving;
    bool fight;
    bool upDown;
    bool leftRight;
    int x;
    int y;
    int deg;
    Soldier (HexPosition loc);
    //void setWay(vector <HexPosition> w);
    void move();
    void attack(HexPosition dest,Soldier* enemy);
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Sprite sprite;
};

#endif // SOLDIER_H
