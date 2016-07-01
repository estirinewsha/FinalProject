#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "queue"
#include "staff/Event.h"
#include "Building.h"
#include "staff/TileMap.h"

namespace netWars
{

class HUD : public sf::Drawable, public sf::Transformable
{
    sf::Sprite *barracksSample;
    sf::Sprite *treasurySample;
    sf::RectangleShape *background;
    std::queue<Building*> buildingQ;
    sf::Mutex buildingQmutex;
public:
    enum Buildings : int {None, Barracks,Treasury};
    int selectedBuilding;
    bool addcoor;
    bool addbuilding;
    int xPose;
    int yPose;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    HUD();
    void eventHandler(Event&);
    Building* getBuilding();
};

}
#endif // HUD_H_INCLUDED
