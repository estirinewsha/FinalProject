#include "Graphic.h"
namespace netWars
{

Graphic::Graphic()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "NetWars");
    window->setFramerateLimit(30);
    window->setMouseCursorVisible(false);
    isOpen = true;

    defaultView = window->getDefaultView();
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
            defaultView.reset(visibleArea);
            sf::View tmp(visibleArea);
            tmp.setCenter(view.getCenter());
            tmp.setRotation(view.getRotation());
            view = tmp;
        }
        if(event.type == sf::Event::MouseWheelMoved)
        {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
            sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos, view);
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
            if(event.mouseButton.button == sf::Mouse::Left)
                output.clicked = true;
            sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
            sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos,view);
            output.mapPos = worldPos;

            worldPos = window->mapPixelToCoords(pixelPos,defaultView);
            output.defaultPos = worldPos;
        }
    }

    if(lastEvent != output)
    {
        eventQmutex.lock();
        eventQ.push(output);
        eventQmutex.unlock();
        lastEvent = output;
    }
}

void Graphic::newOnMap(sf::Drawable* object)
{
    onMaps.push_back(object);
}

void Graphic::newOnHUD(sf::Drawable* object)
{
    onHUDs.push_back(object);
}

void Graphic::drawObjects()
{
    window->clear();

    window->setView(view);

    for(auto obj : onMaps)
    {
        window->draw(*obj);
    }

    window->setView(defaultView);

    for(auto obj : onHUDs)
    {
        window->draw(*obj);
    }

    _cursor->setPosition(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    window->draw(*_cursor);

    window->display();
}

}
