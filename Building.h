#ifndef BUILDING_H
#define BUILDING_H
#include "staff/Event.h"
#include "staff/Cell.h"
using namespace netWars;
class Building: public sf::Drawable, public sf::Transformable
{
    public:
        int num;
        int x;
        int y;
        sf::Sprite *barracksSample;
        sf::Sprite *treasurySample;
        sf::Sprite *castleSample;
        sf::RectangleShape bar;
        sf::Clock clock;
        int type;
        void add(int t);
        void getCoor(int x,int y);
        void gettype(int t);
        Building();
        int setSize(int x);
        static HexPosition convertToHexPos(sf::Vector2f pt);
    protected:
    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class Castel:public Building{
	bool life;
	 void add(int t);
};

class Barracks:public Building{
public:
	 void add(int t);
};

class Treasury:public Building{
public:
	 void add(int t);

};

#endif // BUILDING_H
