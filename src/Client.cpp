#include "Client.h"

namespace netWars
{

Client::Client()
{
    graphic = new Graphic();
    PlayerID = 0;

    tileMap = new netWars::TileMap(netWars::TileMap::SAMPLE);
    graphic->setTM(tileMap);

    hud = new HUD;
    hud->setPosition(0, 600-92);
    graphic->setHUD(hud);
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
        //tileMap->eventHandler(event);
        if(event.isOnMap)
        {
            //event.mousePos =
            ///update->addNewBuilding(event, hud->getStage());
        }
    }
}

}
