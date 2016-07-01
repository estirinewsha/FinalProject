#ifndef BUILDING_H
#define BUILDING_H
#include "staff/Event.h"
#include "staff/Cell.h"
using namespace netWars;
class Building: public sf::Drawable, public sf::Transformable
{
    int num;
    sf::Sprite *sprite;
    sf::RectangleShape bar;
    sf::Clock clock;
    int type;
    HexPosition pos;
    public:
    Building(int type, HexPosition pos);
    void add(int t);
    void getCoor(int x,int y);
    int getType();
    int setSize(int x);
    int getClock();
    HexPosition getPos();
    protected:
    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif // BUILDING_H
