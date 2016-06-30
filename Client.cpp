#include "Client.h"

namespace netWars
{

Client::Client()
{
     window = new sf::RenderWindow(sf::VideoMode(800, 600), "NetWars");
    window->setFramerateLimit(30);
    window->setMouseCursorVisible(false);
    view = window->getDefaultView();
    view.setCenter(0, 0);
    window->setView(view);


    graphic = new Graphic();
    PlayerID = 0;

    player=new Player();

    tileMap = new netWars::TileMap(netWars::TileMap::SAMPLE);
    this->setTM(tileMap);

    hud = new HUD;
    hud->setPosition(0, 600-92);
    this->setHUD(hud);
}
void Client::setTM(TileMap* tm)
{
    this->tileMap = tm;
}

void Client::setHUD(HUD* hud)
{
    this->hud = hud;
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
        graphic->main(event,window,&view);
        this->check();
        this->draw();
    }

}
void Client::check(){
    if(hud->addbuilding){
                int x=hud->xPose;
                int y=hud->yPose;
                if(!player->addnew(100000,1000000,hud->selectedBuilding))
                    std::cout<<"nomoney"<<'\n';
                else{
                    hud->addbuilding=false;
                    hud->addcoor=true;
                }

        }
}
void Client::eventHander()
{
    while(graphic->isOpen)
    {
        Event event = graphic->getEvent();
        player->eventHandler(event,window,&hud->addcoor);
        hud->eventHandler(event);
        if(event.isOnMap)
        {
            //event.mousePos =
            ///update->addNewBuilding(event, hud->getStage());
        }
    }
}
void Client::draw(){
    window->clear();
    window->setView(view);
    window->draw(*tileMap);
    window->draw(*player);
    for(int i=1;i<player->bld.size();i++){
            int x=player->bld[i].clock.getElapsedTime().asSeconds();
            player->bld[i].bar.setSize(sf::Vector2f(x, 20));
            window->draw(player->bld[i].bar);
            player->timing(i);
    }
    for(int i=0;i<player->sld.size();i++){
            window->draw(player->sld[i]);
    }
    window->setView(window->getDefaultView());
    window->draw(*hud);
    graphic->_cursor->setPosition(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    window->draw(*(graphic->_cursor));
    window->display();
}

}
