#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <queue>

#include "staff/Event.h"
#include "Configuration.h"

namespace netWars
{

class Graphic
{
public:
    std::queue<Event> eventQ;
    Event lastEvent;
    sf::Mutex eventQmutex;
    sf::Sprite *_cursor;
   // TileMap* tileMap;
  //  HUD* hud;


    bool isOpen;
//drawObjects(window ,view);
    void eventHandler(sf::Event& event,sf::RenderWindow *window,sf::View *view);
    //void drawObjects(sf::RenderWindow *window,sf::View *view);
public:
    Graphic();
    void start();
    void main(sf::Event& event,sf::RenderWindow *window,sf::View *view);
    Event getEvent();
};

}
#endif // GRAPHIC_H_INCLUDED
