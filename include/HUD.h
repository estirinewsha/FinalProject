#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "vector"
#include "staff/Event.h"
#include "staff/Cell.h"




namespace netWars
{

class HUD : public sf::Drawable, public sf::Transformable
{
    sf::Sprite *barracksSample;
    sf::Sprite *treasurySample;
    sf::RectangleShape *background;
public:
    enum Buildings : int {None, Barracks,Treasury};
    int selectedBuilding;
    bool addcoor;
    bool addbuilding;
    int buildingnum;
    int xPose;
    int yPose;
    std::vector <sf::Clock> clock;
    std::vector <sf::RectangleShape> bars;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    HUD();
    void eventHandler(Event&);
    void addBarCoor(int x,int y,int i);
};

}
#endif // HUD_H_INCLUDED
