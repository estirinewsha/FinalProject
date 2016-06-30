#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <queue>

#include "staff/Event.h"
#include "staff/TileMap.h"
#include "Soldier.h"


namespace netWars
{

class Graphic
{
    sf::View view;
    sf::View defaultView;
    std::queue<Event> eventQ;
    Event lastEvent;
    sf::Mutex eventQmutex;
    sf::Sprite *_cursor;
    TileMap* tileMap;
    Soldier* soldier;
  //  HUD* hud;
public:
    sf::RenderWindow *window;
    bool isOpen;
private:
    void eventHandler();
    void drawObjects();
public:
    Graphic();
    void start();
    void main();
    Event getEvent();
    void setTM(TileMap*);
    void setHUD(HUD*);
};

}
#endif // GRAPHIC_H_INCLUDED
