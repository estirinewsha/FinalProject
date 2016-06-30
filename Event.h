#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <SFML/System/Vector2.hpp>

struct Event
{
    bool clicked = false;
    sf::Vector2f mousePos;
    int isOnMap = false;

    bool operator!=(Event e)
    {
        if(clicked != e.clicked)
            return true;
        if(mousePos != e.mousePos)
            return true;
        return false;
    }
};

#endif // EVENT_H_INCLUDED
