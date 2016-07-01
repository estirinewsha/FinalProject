#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <SFML/System/Vector2.hpp>
#include "Coordinate/HexPosition.h"

struct Event
{
    bool clicked = false;
    sf::Vector2f defaultPos;
    int isOnMap = false;
    sf::Vector2f mapPos;
    netWars::HexPosition* hexPos;
    bool operator!=(Event e)
    {
        if(clicked != e.clicked)
            return true;
        if(defaultPos != e.defaultPos)
            return true;
        return false;
    }
};

#endif // EVENT_H_INCLUDED
