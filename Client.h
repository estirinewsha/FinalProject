#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <vector>

#include "Graphic.h"
#include "HUD.h"
#include "staff/TileMap.h"
namespace netWars
{

class Client
{
public:
    Graphic *graphic;
    netWars::TileMap *tileMap;
    Player *player;
    int PlayerID;
    sf::RenderWindow *window;
    sf::View view;
    sf::Event event;
    HUD *hud;
    sf::Sprite *_cursor;


    void main();
    void eventHander();

    Client();
    void start();
    void draw();
    void setTM(TileMap*);
    void setHUD(HUD*);
    void check();

};

}

#endif // CLIENT_H_INCLUDED
