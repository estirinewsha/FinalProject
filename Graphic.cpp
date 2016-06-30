#include "Graphic.h"
namespace netWars
{

Graphic::Graphic()
{

    isOpen = true;

    _cursor = new sf::Sprite(Configuration::textures.get(Configuration::TexCursor));
}

void Graphic::start()
{

}

void Graphic::main(sf::Event& event,sf::RenderWindow *window,sf::View *view)
{
    eventHandler(event,window ,view);


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

void Graphic::eventHandler(sf::Event& event,sf::RenderWindow *window,sf::View *view)
{
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
            view->setCenter(worldPos);
            if(event.mouseWheel.delta < 0)
            {
                view->zoom(2.0f);
                //zoomLevel *= 2.0f;
            }
            else
            {
                view->zoom(0.5f);
                //zoomLevel *= 0.5f;
            }
        }
        if(event.type == sf::Event::MouseButtonReleased)
        {
            if(event.mouseButton.button == sf::Mouse::Left){
                output.clicked = true;

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
}

}
