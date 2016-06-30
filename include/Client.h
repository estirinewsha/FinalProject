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
    Graphic *graphic;
    netWars::TileMap *tileMap;
    int PlayerID;
    //std::vector<Player*> player;
    HUD *hud;

private:
    void main();
    void eventHander();
public:
    Client();
    void start();

};

}

#endif // CLIENT_H_INCLUDED
