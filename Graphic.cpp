#include "Graphic.h"
namespace netWars
{

Graphic::Graphic()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "NetWars");
    window->setFramerateLimit(30);
    window->setMouseCursorVisible(false);
    isOpen = true;
    view = window->getDefaultView();
    view.setCenter(0, 0);
    window->setView(view);
    _cursor = new sf::Sprite(Configuration::textures.get(Configuration::TexCursor));
}

void Graphic::start()
{

}

void Graphic::main()
{
    eventHandler();

    drawObjects();
}

Event Graphic::getEvent()
{
    Event tmp;
    eventQmutex.lock();
    if(!eventQ.empty())
    {
        tmp = eventQ.front();
        eventQ.pop();
    }
    eventQmutex.unlock();

    return tmp;
}

void Graphic::eventHandler()
{
    sf::Event event;
    Event output;
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            isOpen = false;
        }
        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window->setView(sf::View(visibleArea));
        }
        if(event.type == sf::Event::MouseWheelMoved)
        {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
            sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
            view.setCenter(worldPos);
            if(event.mouseWheel.delta < 0)
            {
                view.zoom(2.0f);
                //zoomLevel *= 2.0f;
            }
            else
            {
                view.zoom(0.5f);
                //zoomLevel *= 0.5f;
            }
        }
        if(event.type == sf::Event::MouseButtonReleased)
        {
            if(event.mouseButton.button == sf::Mouse::Left){
                output.clicked = true;
                if(tileMap->hud->addcoor){
                    tileMap->player->addCoor(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y,tileMap->hud->buildingnum);
                    tileMap->hud->addBarCoor(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y-20,tileMap->hud->buildingnum-1);
                    std::cout<<"clicked"<<sf::Mouse::getPosition(*window).x<<'\n'<<sf::Mouse::getPosition(*window).y<<'\n';
                    tileMap->hud->addcoor=false;
                }
            }

        }
    }
    output.mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));


    if(lastEvent != output)
    {
        eventQmutex.lock();
        eventQ.push(output);
        eventQmutex.unlock();
        lastEvent = output;
    }
}

void Graphic::setTM(TileMap* tm)
{
    this->tileMap = tm;
}

void Graphic::setHUD(HUD* hud)
{
    this->tileMap->hud = hud;
}

void Graphic::drawObjects()
{
    window->clear();

    window->setView(view);
    window->draw(*tileMap);
    window->setView(window->getDefaultView());
    window->draw(*(tileMap->hud));
    _cursor->setPosition(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    window->draw(*_cursor);
    window->display();
}
}