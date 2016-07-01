#include "Client.h"

namespace netWars
{

Client::Client()
{
    graphic = new Graphic();

    tileMap = new netWars::TileMap(netWars::TileMap::SAMPLE);
    graphic->newOnMap(tileMap);

    PlayerID = 0;
    player = new Player();
    graphic->newOnMap(player);

    hud = new HUD;
    hud->setPosition(0, 600-92);
    graphic->newOnHUD(hud);
}

void Client::start()
{
    graphic->start();
    sf::Thread eThread(&Client::eventHander, this);
    eThread.launch();

    this->main();

    eThread.wait();
}

void Client::main()
{
    while(graphic->isOpen)
    {
        graphic->main();
    }
}

void Client::eventHander()
{
    while(graphic->isOpen)
    {
        Event event = graphic->getEvent();

        hud->eventHandler(event);

        {///adding new Buildings
            Building* building = hud->getBuilding();
            if(building!= nullptr)
            {
                if(!player->addBuilding(building))
                    std::cout <<"No Money!";
            }
        }

        player->eventHandler(event);

    }
}

}
